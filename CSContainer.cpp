//
//  CSContainer.cpp
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 8/26/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#include "CSContainer.h"
#include <iterator>

namespace NCSGenerator
{
    CSContainer::CSContainer()
    {

    }
    
    void CSContainer::Add(std::string CharacterSet)
    {
        if(CharacterSet.size() != CSContainer::CHARSETSIZE)
        {
            throw std::runtime_error("Invalid range for provided character set.");
        }
        
        this->_CSContainer.push_back(CharacterSet);
    }
    
    std::vector<std::string> CSContainer::GetContainer()
    {
        return this->_CSContainer;
    }
}