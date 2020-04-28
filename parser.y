%require "3.0"
%debug
%defines
%skeleton "lalr1.cc" 
%define api.namespace {ccbhj}
%define api.parser.class {Parser}
// %define parse.trace
// %define parse.error verbose
%define parse.assert
// keep track of current position 
%locations 
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
#include "tokens.h"
#include "ast.h"
#include <iostream>
#include "context.h"
#include "driver.h"

#undef yylex
#define yylex drv.scanner->yylex

using ccbhj::BiOpt;
using ccbhj::UaOpt;
using ccbhj::Type;
using std::cout;
using std::endl;
}

%union {
    int         TOKEN;
    int         TYPE;
    std::string *STR;
    class ExpNode    *EXPR;
    class StmtNode   *STMT;
    class BlockNode *BLOCK;
    class IdentifierNode *IDENT;
    class Formals *FORMALS;
    class ArgsNode *ARGS;
}

// terminals tokens .
// declare them like: 
//      %token <type> NAME
// <type> must declared into union.
%token <STR>    IDENTIFIER INT_CONST 
%token <TOKEN>  VOID INT
%token <TOKEN>  ASSIGN  
%token <TOKEN>  SEMI COMMA 
%token <TOKEN>  LPAREN RPAREN RBRACE LBRACE LBRACKET RBRACKET
%token <TOKEN>  PLUS MINUS MUL DIV               
%token <TOKEN>  GREATER LESS EQUAL ELESS EGREATER NEQUAL
%token <TOKEN>  IF ELSE RETURN WHILE
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
%type <IDENT> id 
%type <EXPR> numeric expr comparision 
%type <ARGS> args
%type <BLOCK> program declaration_list stmt_list  compound_stmt  
%type <STMT> declaration var_declaration func_declaration param expr_stmt stmt 
%type <STMT> selection_stmt  iteration_stmt  return_stmt
%type <FORMALS> param_list  params
%type <TYPE> var_type 

// start from "program" token
%start  program 


/* Grammar Rules */
%%

program: declaration_list { drv.ctx->programBlock = $1; } 
       | %empty { cout << "empty file to parse" << endl; }
;

id: IDENTIFIER { $$ = new IdentifierNode($1); }
  ;


declaration_list: declaration  {    $$ = new BlockNode(); $$->statements.push_back($1); }
                 | declaration_list declaration    { $$->statements.push_back($2); }
;

declaration: var_declaration  { $$ = $1; }
           | func_declaration  { $$ = $1; }
;

var_declaration: var_type id SEMI { $$ = new Formal($1, $2);}
               | var_type id LBRACKET numeric RBRACKET SEMI { /* TODO array node */ }
;

// variable can only be integer yet.
var_type: INT { $$ = Type::int_; }
;

func_declaration: VOID id LPAREN params RPAREN compound_stmt { $$ = new FuncDeclNode(Type::void_, $2, $4, $6); }
                | var_type id LPAREN params RPAREN compound_stmt { $$ = new FuncDeclNode($1, $2, $4, $6); }
                | error LPAREN param RPAREN compound_stmt { cout << "invalid return type" << endl; yyerrok; }
;


params: %empty { /* no param */ $$ = nullptr;}
      | VOID { $$ = nullptr;}
      | param_list 
;

param_list: param { $$ = new Formals(); $$->formals.push_back(static_cast<Formal*>($1)); }
          | param_list COMMA param { $1->formals.push_back(static_cast<Formal*>($3)); }
;

param: var_type id { $$ = new Formal($1, $2); }
     | var_type id LBRACKET RBRACKET { /* TODO need array type here; */ }
;

// local_declaration is part of stmt_list here 
compound_stmt: LBRACE stmt_list RBRACE  { $$ = $2; }
             | LBRACE /* empty body */ RBRACE { $$ = nullptr;}
;

stmt_list: stmt { $$ = new BlockNode(); $$->statements.push_back($1); }
         | stmt_list stmt { $$->statements.push_back($1); }
;

stmt: expr_stmt
      | compound_stmt { $<STMT>$ = $1;  }
      | selection_stmt 
      | iteration_stmt
      | return_stmt 
;


selection_stmt: IF LPAREN expr RPAREN stmt %prec NO_ELSE {$$ = new SelectNode($3, $5); }                                                           
    | IF LPAREN expr RPAREN stmt ELSE stmt {$$ = new SelectNode($3, $5, $7); }
;

expr_stmt: expr SEMI { $$ = new ExpStmtNode($1); }
        | SEMI { $$ = nullptr; }
;

iteration_stmt: WHILE LBRACE expr RBRACE compound_stmt { $$ = new WhileNode($3, $5); }
;

return_stmt: RETURN SEMI  { $$ = new ReturnNode(); }
           | RETURN expr SEMI { $$ = new ReturnNode($2); }
;

expr: comparision 
    | LPAREN expr RPAREN     { $$ = $2;}
    | expr PLUS expr         { $$ = new BinaryOperator(BiOpt::plus, $1, $3);}
    | expr MINUS expr        { $$ = new BinaryOperator(BiOpt::minus, $1, $3);}
    | expr MUL expr          { $$ = new BinaryOperator(BiOpt::mul, $1, $3);}
    | expr DIV expr          { $$ = new BinaryOperator(BiOpt::div, $1, $3);}
    | MINUS expr %prec NEG   { $$ = new UnaryOperator(UaOpt::neg, $2);}
    | id ASSIGN expr         { $$ = new AsgNode($1, $3); }
    | id LPAREN args RPAREN  { $$ = new MethodCallNode($1, $3); }
    | id LBRACKET expr RBRACKET { /* TODO  array */ }
    | numeric                
    | id                     { $$ = $1; }
;

comparision: expr LESS expr                  { $$ = new BinaryOperator(BiOpt::less, $1, $3);}
    | expr GREATER expr               { $$ = new BinaryOperator(BiOpt::greater,$1, $3);}
    | expr EQUAL expr                 { $$ = new BinaryOperator(BiOpt::equal,$1, $3);}
    | expr NEQUAL expr                { $$ = new BinaryOperator(BiOpt::nequal,$1, $3);}
    | expr ELESS expr                 { $$ = new BinaryOperator(BiOpt::eless,$1, $3);}
    | expr EGREATER expr              { $$ = new BinaryOperator(BiOpt::egreater ,$1, $3);}
;

numeric: INT_CONST  { $$ = new NumNode(std::stoi(*$1)); delete $1; }
;

args: %empty { $$ = nullptr; }
    | expr  { $$ = new ArgsNode(); $$->args.push_back($1); }
    | args COMMA expr { $1->args.push_back($3); }

%%
void ccbhj::Parser::error(const Parser::location_type& l, const std::string& m) {
    drv.error(l, m);
}
