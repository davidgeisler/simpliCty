#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexers.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: correct syntax: %s <filename.cty>\n", argv[0]);
        exit(1);
    }

    // Open the input file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("ERROR: File not found\n");
        exit(1);
    }

    // Open the output file for the symbol table
    FILE *symbol_table = fopen("symbol_table.txt", "w");
    if (!symbol_table) {
        printf("ERROR: Unable to create the output file\n");
        fclose(file);
        exit(1);
    }

    // Tokenize the input file
    size_t token_count = 0;
    Token **tokens = lexer(file, &token_count);
    fclose(file);

    // Print and write tokens to the symbol table
    printf("Tokens generated:\n");
    for (size_t i = 0; i < token_count; i++) {
        print_token(tokens[i]);                          // Display tokens in the console
        write_to_symbol_table(tokens[i], symbol_table);  // Write tokens to the output file
    }

    fclose(symbol_table);

    // Clean up allocated memory for tokens
    for (size_t i = 0; i < token_count; i++) {
        free_token(tokens[i]);
    }
    free(tokens);

    printf("Lexical analysis complete. Check 'symbol_table.txt' for results.\n");
    return 0;
}