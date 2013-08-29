//
//  CSGenerator.cpp
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 7/10/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#include "CSGenerator.h"
#include "CSContainer.h"
#include <sstream>

namespace NCSGenerator
{
    CSGenerator::CSGenerator()
    {
    }
    
    CSGenerator::~CSGenerator()
    {
        
    }
    
    void CSGenerator::SetLoopDelay(unsigned int LoopDelay)
    {
        this->LoopDelay = LoopDelay;
    }
    
    unsigned int CSGenerator::GetLoopDelay()
    {
        return this->LoopDelay;
    }
    
    void CSGenerator::Generate()
    {
        unsigned long Combination = 0;
        
        for(int i = 0; i < 100; i++)
        {
            Combination = Combination + this->GetLoopDelay();
            std::string ByteString = this->Dec2bin(Combination);
            std::string CharString = "";
            
            for(int i = 0; i < ByteString.size(); i = i + 5)
            {
                std::string ByteChunk = ByteString.substr(i,5);
                unsigned long index = std::bitset<std::numeric_limits<unsigned long>::digits>(ByteChunk).to_ulong();
                CharString += this->CharacterSet[index];
            }
            
            this->CSContainer->Add(CharString);
        }
    }
    
    std::string CSGenerator::Dec2bin(unsigned long n)
    {
        std::string res;
        res.reserve(5 * 8);
        
        while (n)
        {
            res.push_back((n & 1) + '0');
            n >>= 1;
        }

        while(res.size() < 5 * 8)
        {
            res.append("0");
        }
        
        std::reverse(res.begin(), res.end());
        
        return res;
    };
}