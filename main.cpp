//     _______ ____     
//    / ____(_) / /_  __
//   / /   / / / / / / /
//  / /___/ / / / /_/ / 
//  \____/_/_/_/\__, /  
//             /____/  
//
//  This file is a part of the Cilly project
//  Made by Dudin Elisey 

#include "include/llvm_ir.hpp"
#include "include/token.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        throw std::runtime_error("No input file");
    }

    auto tokens = get_tokens(argv[1]);
    for (auto tok : tokens)
    {
        printf("TYPE: %d, DATA: %s\n", tok.first, tok.second.c_str());
    }

    return 0;
}

