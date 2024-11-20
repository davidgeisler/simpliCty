#ifndef LEXER_H_   
#define LEXER_H_

#include <stddef.h> 
#include <stdio.h>  

// Enum to define different types of tokens
typedef enum {
    TOKEN_KEYWORD,                // Keywords (e.g., if, else, for)
    TOKEN_RESERVED_WORD,          // Reserved words (e.g., int, float, boolean)
    TOKEN_IDENTIFIER,             // Variable or function names
    TOKEN_NUMBER,                 // Numeric constants (e.g., 123, 45.67)
    TOKEN_ARITHMETIC_OPERATOR,    // Arithmetic operators (e.g., +, -, *, /)
    TOKEN_RELATIONAL_OPERATOR,    // Relational operators (e.g., <, >, ==)
    TOKEN_LOGICAL_OPERATOR,       // Logical operators (e.g., &&, ||, !)
    TOKEN_ASSIGNMENT_OPERATOR,    // Assignment operators (e.g., =, +=)
    TOKEN_UNARY_OPERATOR,         // Unary operators (e.g., ++, --)
    TOKEN_DELIMITER,              // Delimiters (e.g., ;, {}, [])
    TOKEN_STRING,                 // String literals (e.g., "Hello")
    TOKEN_NOISE_WORD,             // Words that have no specific meaning in the language
    TOKEN_COMMENT,                // Comments (e.g., ~~ for single-line, ~^ ^~ for multi-line)
    TOKEN_UNKNOWN,                // Invalid or unrecognized tokens
    TOKEN_EOF                     // End-of-file marker
} TokenType;

// Structure to represent a token
typedef struct {
    TokenType type;               // Token type
    char *value;                  // (e.g., "if", "123")
    size_t line_num;      
} Token;

// Printing of tokens
void print_token(const Token *token);

// Main lexer function to process an input file and generate tokens
Token **lexer(FILE *file, size_t *token_count);

//Function to write a token to a symbol table (output file)
void write_to_symbol_table(const Token *token, FILE *symbol_table_file);

// Free memory allocated for a token
void free_token(Token *token);

#endif                            // LEXER_H_
