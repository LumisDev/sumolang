#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

enum class Token {
    tok_eof = -1,

    // Keywords
    tok_public = -2,
    tok_private = -3,
    tok_class = -4,
    tok_array = -5,
    tok_string = -6,
    tok_println = -7,
    tok_void = -8,
    tok_int = -9,
    tok_float = -10,
    tok_readln = -11,
    tok_end = -12,

    // Primary
    tok_identifier = -13,
    tok_number = -14
};

class Lexer {
    std::string SourceCode;
    size_t CurrentIndex;
    char CurrentChar;

    void Advance();
    void SkipWhitespace();
    void SkipComment();
    Token ReadIdentifier();
    Token ReadNumber();

public:
    Lexer(const std::string &Source);
    
    Token GetNextToken();
    std::string GetTokenString(Token T);
};

#endif // LEXER_HPP
