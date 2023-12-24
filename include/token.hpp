//     _______ ____     
//    / ____(_) / /_  __
//   / /   / / / / / / /
//  / /___/ / / / /_/ / 
//  \____/_/_/_/\__, /  
//             /____/  
//
//  This file is a part of the Cilly project
//  Made by Dudin Elisey 

#include "shared.hpp"
#include <fstream>

//Get token from string
//TODO: Count the amount of special characters in floats/ints
//Use count_chars from shared.hpp:39:42
bool is_int(const std::string& s)
{
    return s.find_first_not_of("-0123456789") == std::string::npos;
}

bool is_float(const std::string& s)
{
    return s.find_first_not_of("-0123456789.") == std::string::npos;
}

bool is_str(const std::string& s)
{
    return s[0] == '"' && s.back() == '"';
}

bool is_bool(const std::string& s)
{
    return s == "true" || s == "false";
}

int identify_keyword(const std::string& s)
{
    //TODO
    return 0;
}

int get_token(const std::string& s)
{
    if (is_int(s)) return token_types::TOKEN_INT_REPR;
    if (is_float(s)) return token_types::TOKEN_FLT_REPR;
    if (is_str(s)) return token_types::TOKEN_STR_REPR;
    if (is_bool(s)) return token_types::TOKEN_BOOL_REPR;

    return token_types::TOKEN_NULL;
}

//TODO: Give it an ability to read array literals; no (file >> str) basically
std::vector<token> get_tokens(const char * path)
{
    std::fstream file;
    std::string str;
    std::vector<token> tokens;

    file.open(path);

    while (file >> str)
    {
        tokens.push_back(
            token
            (
                get_token(str),
                str
            )
        );
    }

    file.close();

    return tokens;
}