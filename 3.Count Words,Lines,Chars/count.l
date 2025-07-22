%{
int lines = 0, words = 0, chars = 0;
%}

%%
\n          { lines++; chars++; }
[ \t]+      { chars += yyleng; }
[^ \t\n]+   { words++; chars += yyleng; }
.           { chars++; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nStatistics:\n");
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    return 0;
}
