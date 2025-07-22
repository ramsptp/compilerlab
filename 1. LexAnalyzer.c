#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    FILE *f1;
    char c, peek, str[64];
    int lineno = 1, num = 0, i = 0;

    f1 = fopen("input.txt", "r");
    if (f1 == NULL) {
        printf("Cannot open file.\n");
        return;
    }

    while ((c = getc(f1)) != EOF) {
//single line
        if	 (c == '/') {
            peek = getc(f1);
            if (peek == '/') {
                while ((c = getc(f1)) != EOF && c != '\n');
                lineno++;
                continue;
            }
//multi
            else if (peek == '*') {
                int prev = 0;
                while ((c = getc(f1)) != EOF) {
                    if (c == '\n') lineno++;
                    if (prev == '*' && c == '/') break;
                    prev = c;
                }
                if (c == EOF) {
                    printf("Error: Unterminated comment at line %d\n", lineno);
                }
                continue;
            }

            else {
                if (peek == '=') {
                    printf("/= is an arithmetic operator\n");
                } else {
                    printf("/ is an arithmetic operator\n");
                    ungetc(peek, f1);
                }
                continue;
            }
        }


        if (isdigit(c)) {
            num = c - '0';
            c = getc(f1);
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                c = getc(f1);
            }
            printf("%d is a number\n", num);
            ungetc(c, f1);
        }


        else if (isalpha(c) || c == '_') {
            i = 0;
            str[i++] = c;
            c = getc(f1);
            while (isalnum(c) || c == '_') {
                str[i++] = c;
                c = getc(f1);
            }
            str[i] = '\0';

            if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 ||
                strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 ||
                strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 ||
                strcmp("case", str) == 0)
                printf("%s is a keyword\n", str);
            else
                printf("%s is an identifier\n", str);

            ungetc(c, f1);
        }


        else if (c == ' ' || c == '\t') {
	printf("\n");
        } else if (c == '\n') {
            lineno++;
        }


        else if (strchr("+-*=!<>", c)) {
            peek = getc(f1);
            if (c == '+' && peek == '+')
                printf("++ is an arithmetic operator\n");
            else if (c == '-' && peek == '-')
                printf("-- is an arithmetic operator\n");
            else if (c == '=' && peek == '=')
                printf("== is a relational operator\n");
            else if (c == '!' && peek == '=')
                printf("!= is a relational operator\n");
            else if (c == '<' && peek == '=')
                printf("<= is a relational operator\n");
            else if (c == '>' && peek == '=')
                printf(">= is a relational operator\n");
            else {
            if(c == '=')
        	printf("%c is the assignment operator\n",c);
             else if(c == '>' || c=='<')
        	printf("%c is a relational operator\n",c);
             else if(c == '>' || c=='<')
        	printf("%c is a relational operator\n",c);
        else
                printf("%c is an operator\n", c);
                ungetc(peek, f1);
            }
        }


        else {
        if(c == '$'){
        int k=10;
        }
        
        else
            printf("%c is a special symbol\n", c);
        }
    }

    printf("Total no. of lines are: %d\n", lineno);
    fclose(f1);
}

