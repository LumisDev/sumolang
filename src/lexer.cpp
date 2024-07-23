#include "lexer.hpp"
#include <cctype>
#include <stdexcept>

// Constructor to initialize the lexer with source code
Lexer::Lexer(const std::string &Source) : SourceCode(Source), CurrentIndex(0), CurrentChar(Source.empty() ? '\0' : Source[0]) {}

// Advances to the next character in the source code
void Lexer::Advance() {
    if (CurrentIndex + 1 < SourceCode.size()) {
        ++CurrentIndex;
        CurrentChar = SourceCode[CurrentIndex];
    } else {
        CurrentChar = '\0'; // End of source code
    }
}

// Skips whitespace characters
void Lexer::SkipWhitespace() {
    while (std::isspace(CurrentChar)) {
        Advance();
    }
}

// Skips comments (single line, assuming `//` for comments)
void Lexer::SkipComment() {
    while (CurrentChar != '\n' && CurrentChar != '\0') {
        Advance();
    }
}

// Reads an identifier (variable names, keywords, etc.)
Token Lexer::ReadIdentifier() {
    std::string Identifier;

    while (std::isalnum(CurrentChar) || CurrentChar == '_') {
        Identifier += CurrentChar;
        Advance();
    }

    if (Identifier == "public") return Token::tok_public;
    if (Identifier == "private") return Token::tok_private;
    if (Identifier == "class") return Token::tok_class;
    if (Identifier == "array") return Token::tok_array;
    if (Identifier == "string") return Token::tok_string;
    if (Identifier == "println") return Token::tok_println;
    if (Identifier == "void") return Token::tok_void;
    if (Identifier == "int") return Token::tok_int;
    if (Identifier == "float") return Token::tok_float;
    if (Identifier == "readln") return Token::tok_readln;
    if (Identifier == "end") return Token::tok_end;

    return Token::tok_identifier; // Default identifier token
}

// Reads a number (integer or float)
Token Lexer::ReadNumber() {
    std::string Number;

    while (std::isdigit(CurrentChar) || CurrentChar == '.') {
        Number += CurrentChar;
        Advance();
    }

    return Token::tok_number; // Return number token (parse value later if needed)
}

// Gets the next token from the source code
Token Lexer::GetNextToken() {
    while (CurrentChar != '\0') {
        if (std::isspace(CurrentChar)) {
            SkipWhitespace();
            continue;
        }

        if (CurrentChar == '/') {
            Advance();
            if (CurrentChar == '/') {
                SkipComment();
                continue;
            } else {
                // Handle division operator or other cases if needed
            }
        }

        if (std::isalpha(CurrentChar) || CurrentChar == '_') {
            return ReadIdentifier();
        }

        if (std::isdigit(CurrentChar)) {
            return ReadNumber();
        }

        // Handle other tokens (punctuation, operators, etc.) as needed

        throw std::runtime_error("Unexpected character: " + std::string(1, CurrentChar));
    }

    return Token::tok_eof; // End of file
}

// Returns a string representation of the token
std::string Lexer::GetTokenString(Token T) {
    switch (T) {
        case Token::tok_eof: return "EOF";
        case Token::tok_public: return "public";
        case Token::tok_private: return "private";
        case Token::tok_class: return "class";
        case Token::tok_array: return "array";
        case Token::tok_string: return "string";
        case Token::tok_println: return "println";
        case Token::tok_void: return "void";
        case Token::tok_int: return "int";
        case Token::tok_float: return "float";
        case Token::tok_readln: return "readln";
        case Token::tok_identifier: return "identifier";
        case Token::tok_number: return "number";
        case Token::tok_end: return "end";
        default: return "unknown";
    }
}
