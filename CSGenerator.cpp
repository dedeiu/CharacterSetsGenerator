//
//  CSGenerator.cpp
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 7/10/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#include "CSGenerator.h"

namespace NCSGenerator
{
    CSGenerator::CSGenerator()
    {
    }
    
    CSGenerator::~CSGenerator()
    {
        
    }
    
    void CSGenerator::setLoopDelay(unsigned int loopDelay)
    {
        this->loopDelay = loopDelay;
    }
    unsigned int CSGenerator::getLoopDelay()
    {
        return this->loopDelay;
    }
}