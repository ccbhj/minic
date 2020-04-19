%require "3.0"
%debug
%defines
%skeleton "lalr1.cc" 
%define api.namespace {ccbhj}
%define api.parser.class {Parser}
%code requires {
    namespace ccbhj {
        class Driver;
        class Scanner;
    }
    #include "location.hh"
// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { Driver& drv}

%initial-action
{
    @$.begin.filename = @$.end.filename = &drv.output;
}

%code{
#include "ast.h"
#include <iostream>
#include "tinyContext.h"
#include "driver.h"

#undef yylex
#define yylex drv.scanner->yylex

using ccbhj::BiOpt;
using ccbhj::UaOpt;
}
%define parse.assert

%union {
    int         TOKEN;
    std::string *STR;
    class BlockNode*  BLOCK;
    class ExpNode*    EXPR;
    class StmtNode*   STMT;
    class IdentifierNode* IDENT;
}


// terminals tokens .
// declare them like: 
//      %token <type> NAME
// <type> must declared into union.
%token <STR>    IDENTIFIER INT_CONST
%token <TOKEN>  ASSIGN 
%token <TOKEN>  SEMI COMMA 
%token <TOKEN>  LPAREN RPAREN RBRACE LBRACE LBRACKET RBRACKET
%token <TOKEN>  PLUS MINUS MUL DIV               
%token <TOKEN>  GREATER LESS EQUAL ELESS EGREATER NEQUAL
%token <TOKEN>  IF ELSE RETURN WHILE
%token <TOKEN>  INT VOID
%token <TOKEN>  END                 0               "end of file"

%nonassoc LPAREN RPAREN
%left ASSIGN
%left GREATER LESS EQUAL ELESS EGREATER NEQUAL
%left PLUS MINUS
%left MUL DIV
%precedence NEG 

%nonassoc NO_ELSE
%nonassoc ELSE


// declare non-terminal here
%type <IDENT> ident
%type <EXPR> numeric expr comparision
%type <BLOCK> program stmts 
%type <STMT> stmt if_stmt while_stmt for_stmt


%start  program
%locations // keep track of current position 

/* Grammar Rules */
%%

// TODO

stmts: stmt  {
                $$ = new BlockNode();
                $$->statements.push_back($1);
            }
    | stmts stmt    {
                        $$->statements.push_back($2);
                    }
;

stmt: expr SEMI { $$ = new ExpStmtNode($1); }
    | if_stmt   
    | while_stmt
    | for_stmt
    | error SEMI    { yyerrok; }
    | expr error    { printf("missing ';'\n"); yyerrok; }
;

if_stmt: IF LPAREN comparision RPAREN stmts %prec NO_ELSE {$$ = new SelectNode($3, $5); }
    | IF LPAREN comparision RPAREN  stmts ELSE stmts {$$ = new SelectNode($3, $5, $7); }
    ;

while_stmt:
    WHILE  comparision  DO stmts ENDWHILE { $$ = new WhileNode($2, $4); }
    | WHILE  comparision  DO ENDWHILE { $$ = new WhileNode($2); }
    | DO stmts WHILE LPAREN comparision RPAREN    { $$ = new WhileNode($5, $2); }
;

for_stmt:
    FOR ident ASSIGN expr TO expr DO stmts ENDDO {
                    $$ = new ForNode(true, new AsgNode($2, $4), $6, $8); }
    | FOR ident ASSIGN expr DOWNTO expr DO stmts ENDDO {
                    $$ = new ForNode(false, new AsgNode($2, $4), $6, $8); }
;
numeric: INT_CONST  {
                        $$ = new NumNode(std::stoi(*$1));
                    }
;

ident: IDENTIFIER { $$ = new IdentifierNode(*$1); }
;

expr: ident ASSIGN expr             { $$ = new AsgNode($1, $3); }
    | comparision               
    | LPAREN expr RPAREN            { $$ = $2;}
    | expr PLUS expr                 { $$ = new BinaryOperator(BiOpt::plus, $1, $3);}
    | expr MINUS expr               { $$ = new BinaryOperator(BiOpt::minus, $1, $3);}
    | expr MUL expr                 { $$ = new BinaryOperator(BiOpt::mul, $1, $3);}
    | expr DIV expr                 { $$ = new BinaryOperator(BiOpt::div, $1, $3);}
    | MINUS expr %prec NEG          { $$ = new UnaryOperator(UaOpt::neg, $2);}
    | ident                         { $$ = $1;}
    | numeric                       
;

comparision: 
     expr LESS expr                  { $$ = new BinaryOperator(BiOpt::less, $1, $3);}
    | expr GREATER expr               { $$ = new BinaryOperator(BiOpt::greater,$1, $3);}
    | expr EQUAL expr                 { $$ = new BinaryOperator(BiOpt::equal,$1, $3);}
    | expr NEQUAL expr                { $$ = new BinaryOperator(BiOpt::nequal,$1, $3);}
    | expr ELESS expr                 { $$ = new BinaryOperator(BiOpt::eless,$1, $3);}
    | expr EGREATER expr              { $$ = new BinaryOperator(BiOpt::egreater ,$1, $3);}
;

program: 
    stmts { 
        drv.ctx->programBlock = $1; }
    ;
%%
void ccbhj::Parser::error(const Parser::location_type& l, const std::string& m) {
    drv.error(l, m);
}
