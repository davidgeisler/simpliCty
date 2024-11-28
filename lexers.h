#ifndef LEXER_H_
#define LEXER_H_

#include <stddef.h>
#include <stdio.h>  // Add this line to include the FILE type

typedef enum {
    TOKEN_IDENTIFIER,
    
    TOKEN_KEYWORD,
    TOKEN_RESERVED_WORD,
    TOKEN_NOISE_WORD,

    TOKEN_CONST_INTEGER,
    TOKEN_CONST_FLOAT,
    TOKEN_CONST_STRING,
    TOKEN_CONST_CHARACTER,
    TOKEN_CONST_BOOL,

    TOKEN_ARITHMETIC_OPERATOR,
    TOKEN_BOOLEAN_RELATIONAL_OPERATOR,
    TOKEN_BOOLEAN_LOGICAL_OPERATOR,
    TOKEN_ASSIGNMENT_OPERATOR,
    TOKEN_UNARY_OPERATOR,
    
    TOKEN_DELIMITER,
    
    TOKEN_BRACKET_OPEN_PARENTHESIS,
    TOKEN_BRACKET_CLOSE_PARENTHESIS,
    TOKEN_BRACKET_OPEN_BRACE,
    TOKEN_BRACKET_CLOSE_BRACE,
    TOKEN_BRACKET_OPEN_BRACKET,
    TOKEN_BRACKET_CLOSE_BRACKET,
    
    TOKEN_COMMENT,
    
    TOKEN_UNKNOWN,
    TOKEN_INVALID,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char *value;
    size_t line_num;
} Token;

typedef enum {
    START_STATE,
    IDENTIFIER_STATE,
    INTEGER_STATE,
    FLOAT_STATE,
    STRING_STATE,
    CHAR_STATE,
    OPERATOR_STATE,
    DELIMITER_STATE,
    INVALID_STATE
} State;

void print_token(const Token *token);
Token **lexer(FILE *file, size_t *token_count);
void write_to_symbol_table(const Token *token, FILE *symbol_table_file);

#endif // LEXER_H_