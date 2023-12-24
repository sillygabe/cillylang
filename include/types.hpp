#include <cstddef>
#include <utility>
#include <string>
#pragma once

using token = std::pair<int, std::string>;

enum token_types
{
    //REPR as in representation
    TOKEN_NULL = -1,
    TOKEN_INT_REPR = 1,
    TOKEN_FLT_REPR = 2,
    TOKEN_STR_REPR = 3,
    //OPER as in operator
    TOKEN_OPER_PLUS = 4, // +
    TOKEN_OPER_MINUS = 5,// -
    TOKEN_OPER_MULTIPLY = 6, // *,
    TOKEN_OPER_TRUE_DIV = 7, // /
    TOKEN_OPER_DIV = 8, // //
    TOKEN_OPER_MOD = 9, // %
    TOKEN_OPER_TOFORCE = 10 // ^
    
};