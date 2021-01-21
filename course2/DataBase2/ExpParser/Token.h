//
// Created by apel on 17.01.2021.
//

#ifndef YANDEX_CPP_COURSE_TOKEN_H
#define YANDEX_CPP_COURSE_TOKEN_H

#include <sstream>
#include <vector>


enum class TokenType {
    DATE,
    EVENT,
    COLUMN,
    LOGICAL_OP,
    COMPARE_OP,
    PAREN_LEFT,
    PAREN_RIGHT,
};

struct Token {
    const std::string value;
    const TokenType type;
};

std::vector<Token> Tokenize(std::istream &cl);


#endif //YANDEX_CPP_COURSE_TOKEN_H
