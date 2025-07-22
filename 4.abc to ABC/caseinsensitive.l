%{
#include <stdio.h>
%}

%%
[aA][bB][cC]    { printf("ABC"); }
.               { printf("%c", yytext[0]); }
\n              { printf("\n"); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    return 0;
}
