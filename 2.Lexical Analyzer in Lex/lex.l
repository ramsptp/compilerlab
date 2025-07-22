%{
#include <stdio.h>
#include <string.h>

int line_count = 1;
int token_count = 0;
%}

/* Regular definitions */
digit       [0-9]
letter      [a-zA-Z]
identifier  {letter}({letter}|{digit})*
integer     {digit}+
real        {digit}+\.{digit}+
string      \"[^\"]*\"

%%

/* Keywords */
int|float|char|double|void|if|else|while|for|do|switch|case|break|continue|return|struct|typedef    {
    printf("KEYWORD: %s\n", yytext);
    token_count++;
}

/* Identifiers */
{identifier}    {
    printf("IDENTIFIER: %s\n", yytext);
    token_count++;
}

/* Numbers */
{integer}       {
    printf("INTEGER: %s\n", yytext);
    token_count++;
}

{real}          {
    printf("REAL: %s\n", yytext);
    token_count++;
}

/* Strings */
{string}        {
    printf("STRING: %s\n", yytext);
    token_count++;
}

/* Operators */
"+"|-|"*"|\/|%|=|"=="|"!="|"<"|">"|"<="|">="    {
    printf("OPERATOR: %s\n", yytext);
    token_count++;
}

/* Logical Operators */
"&&"|"||"|"!"   {
    printf("LOGICAL_OP: %s\n", yytext);
    token_count++;
}

/* Delimiters */
";"|","|"("|")"|"{"|"}"|"["|"]"    {
    printf("DELIMITER: %s\n", yytext);
    token_count++;
}

/* Preprocessor directives */
#[a-zA-Z]+      {
    printf("PREPROCESSOR: %s\n", yytext);
    token_count++;
}

/* Comments */
\/\*([^*]|\*+[^*/])*\*+\/   {
    printf("COMMENT: %s\n", yytext);
    token_count++;
}

\/\/.*          {
    printf("COMMENT: %s\n", yytext);
    token_count++;
}

/* Whitespace */
[ \t]+          { /* ignore whitespace */ }

/* Newlines */
\n              { line_count++; }

/* Any other character */
.               {
    printf("UNKNOWN: %s\n", yytext);
}

%%

int yywrap() {
    return 1;
}