//     _______ ____     
//    / ____(_) / /_  __
//   / /   / / / / / / /
//  / /___/ / / / /_/ / 
//  \____/_/_/_/\__, /  
//             /____/  
//
//  This file is a part of the Cilly project
//  Made by Dudin Elisey 

#include <cstddef>
#include <utility>
#include <exception>
#include <string>
#include <vector>
#include <algorithm>
#pragma once

using token = std::pair<int, std::string>;

enum token_types
{
    //REPR as in representation
    TOKEN_NULL = -1,
    TOKEN_INT_REPR = 1,
    TOKEN_FLT_REPR = 2,
    TOKEN_STR_REPR = 3,
    TOKEN_BOOL_REPR = 4,
    //OPER as in operator
    TOKEN_OPER_PLUS = 5, // +
    TOKEN_OPER_MINUS = 6, // -
    TOKEN_OPER_MULTIPLY = 7, // *
    TOKEN_OPER_TRUE_DIV = 8, // /
    TOKEN_OPER_DIV = 9, // //
    TOKEN_OPER_MOD = 10, // %
    TOKEN_OPER_TOFORCE = 11 // ^
};

size_t count_chars(const std::string& s, char elem)
{
    return std::count(s.begin(), s.end(), elem);
}