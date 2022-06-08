// Mylanguage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "lexer.h"
#include <iostream>
#include <map>
#include <string>
#pragma warning( disable : 4996)
int main(int argc, char **argv)
{
    FILE *fpath;

    const char *mode = "r";
    char buffer[1024];

    std::map<const char*, int> userInt;

    fpath = fopen(argv[1], mode);

    getline(buffer, fpath, 0);

    if (checkVar(buffer))
        if (getVarType(buffer) == 1)
        {
            char name[10];
            getVarName(buffer, name);
            userInt.insert({name, getValueInt(buffer) });
        }
            
    

    
}
