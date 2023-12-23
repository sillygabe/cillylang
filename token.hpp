/* _______ ____     
  / ____(_) / /_  __
 / /   / / / / / / /
/ /___/ / / / /_/ / 
\____/_/_/_/\__, /  
           /____/  
//
//  This file is a part of the Cilly project
//  Made by Dudin Elisey 
*/

#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <vector>

enum token_types
{
    TOKEN_NULL = -1,
    TOKEN_INT_REPR = 1,
    TOKEN_FLT_REPR = 2,
    TOKEN_STR_REPR = 3
    //REPR as in representation
};

using token = std::pair<int, std::string>;

//Get token from string :3
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

int get_token(const std::string& s)
{
    if (is_int(s)) return token_types::TOKEN_INT_REPR;
    if (is_float(s)) return token_types::TOKEN_FLT_REPR;
    if (is_str(s)) return token_types::TOKEN_STR_REPR;

    return token_types::TOKEN_NULL;
}
/////////////////////////////////////////////

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

    for (auto tok : tokens)
    {
        std::cout << "TYPE: " << tok.first << " DATA: " << tok.second << std::endl;
    }

    file.close();

    return tokens;
}