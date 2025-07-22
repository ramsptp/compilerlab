int main() {
    printf("Enter C program (Ctrl+D to end):\n");
    printf("========================================\n");
    
    yylex();
    
    printf("========================================\n");
    printf("Analysis Complete!\n");
    printf("Total tokens: %d\n", token_count);
    printf("Total lines: %d\n", line_count);
    
    return 0;
}
