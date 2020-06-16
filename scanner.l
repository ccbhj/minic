
%{
/* code to be put into the lexer.h*/
#include <string>


#include "tokens.h"
#include "scanner.h"
#undef YY_DECL
#define YY_DECL ccbhj::Parser::token_type ccbhj::Scanner::yylex( ccbhj::Parser::semantic_type* const yylval, ccbhj::Parser::location_type* loc)

using token = ccbhj::Parser::token;
using token_type = ccbhj::Parser::token_type;
using type = ccbhj::Type;
#define yyterminate()  return (token::END)
#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option yylineno
%option nodefault
%option yyclass="ccbhj::Scanner"
%option noyywrap
%option c++

%x COMMENT  
    /* pattern macro */
%%


"/*"             { BEGIN(COMMENT);}
<COMMENT>"*/"    { BEGIN(INITIAL);}
<COMMENT>\n     { /* muliple line comment*/ }
<COMMENT>.      { /* do noting */}

","         { return token::COMMA; }
";"         { return token::SEMI; }
"="         { return token::ASSIGN; }
"("         { return token::LPAREN; }
")"         { return token::RPAREN; }
"}"         { return token::RBRACE; }
"{"         { return token::LBRACE; }
"["         { return token::LBRACKET; }
"]"         { return token::RBRACKET; }
"+"         { return token::PLUS; }
"-"         { return token::MINUS; }
"*"         { return token::MUL; }
"/"         { return token::DIV; }
"=="        { return token::EQUAL; }
"!="        { return token::NEQUAL; }
"<"         { return token::LESS; }
">"         { return token::GREATER; }
"<="        { return token::ELESS;}
">="        { return token::EGREATER; }
"int"       { return token::INT; }
"void"      { return token::VOID; }
"if"        { return token::IF; }
"else"      { return token::ELSE; }
"while"     { return token::WHILE; }
"return"    { return token::RETURN; }

[0-9]+      {
                yylval->STR = new std::string(yytext, yyleng);
                return token::INT_CONST;
            }
[A-Za-z_]+[A-Za-z0-9_]*    { 
                yylval->STR = new std::string(yytext, yyleng);
                return token::IDENTIFIER;
            }

[ \t\r]+    { loc->step(); }

\n          { 
                loc->lines();
            }
.           { throw ccbhj::Parser::syntax_error
                    (*loc, "invalid character: " + std::string(yytext));
            }

%%

