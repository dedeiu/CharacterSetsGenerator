//
//  CSGenerator.h
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 7/10/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#ifndef __CharacterSetsGenerator__CSGenerator__
#define __CharacterSetsGenerator__CSGenerator__

#include <iostream>
#include "CSContainer.h"

namespace NCSGenerator
{
    class CSGenerator
    {
        
    private:
        unsigned int LoopDelay = 9999;
        // Current BuildCharSet(int combination) method will work only with a length of 32 elements
        // for char[] characters. However if you change the length, a new algorithm
        // implementation for BuildCharSet(int combination) method is needed.
        // I.E.: For a length of 8 character / code you need 8 loop, or even better
        // a recursive method.
        const char CharacterSet[32] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M','N', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        CSContainer* CSContainer = new NCSGenerator::CSContainer();
        std::string Dec2bin(unsigned long n);
        int BinToInt(std::string const& s);
    public:
        CSGenerator();
        ~CSGenerator();
        void SetLoopDelay(unsigned int LoopDelay);
        unsigned int GetLoopDelay();
        void Generate();
    };
}
#endif /* defined(__CharacterSetsGenerator__CSGenerator__) */