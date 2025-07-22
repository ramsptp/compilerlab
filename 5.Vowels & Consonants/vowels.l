%{
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]        { vowels++; }
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]    { consonants++; }
.                   { /* ignore other characters */ }
\n                  { /* ignore newlines */ }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();
    printf("\nResults:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
