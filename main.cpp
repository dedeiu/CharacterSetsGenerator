//
//  main.cpp
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 7/10/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#include <iostream>
#include "CSContainer.h"

int main(int argc, const char * argv[])
{

    try
    {
        std::string test[5];
        test[0] = "ABCDEFG0";
        test[1] = "ABCDEFG1";
        test[2] = "ABCDEFG2";
        test[3] = "ABCDEFG3";
        test[4] = "ABCDEFG4";
        
        NCSGenerator::CSContainer* container = new NCSGenerator::CSContainer();
        
        for(int i = 0; i < 5; i++)
        {
            container->Add(test[i]);
        }
        
        std::vector<std::string> p = container->GetContainer();
        
    }
    catch (std::exception& e)
    {
        std::cout << "Error " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

