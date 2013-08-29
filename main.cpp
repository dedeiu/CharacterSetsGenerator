//
//  main.cpp
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 7/10/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#include <iostream>
#include "CSGenerator.h"

int main(int argc, const char * argv[])
{
    try
    {
        NCSGenerator::CSGenerator* Generator = new NCSGenerator::CSGenerator();
        Generator->Generate();

    }
    catch (std::exception& e)
    {
        std::cout << "Error " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

