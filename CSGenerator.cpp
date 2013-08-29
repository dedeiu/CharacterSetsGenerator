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
#include <fstream>

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
        std::string CharString(8, 'A');
        std::string ByteString(this->CharByteStringLength * 8, '0');
        std::string ByteChunk(8, '0');
        unsigned long CharacterSetIndex = 0;
        
        for(int i = 0; i < this->NumberOfCodes; i++)
        {
            if(i % CSContainer::BUFFER == 0 && i > 0)
            {
                std::ofstream OutputFile(this->FilePath, std::ios::app);
                std::ostream_iterator<std::string> OutputIterator(OutputFile, "\n");
                std::vector<std::string> container = this->CSContainer->GetContainer();
                std::copy(container.begin(), container.end(), OutputIterator);
                this->CSContainer->Empty();
            }
            
            Combination = Combination + this->GetLoopDelay();
            ByteString = this->Dec2bin(Combination);
            CharString = "";
            
            for(int i = 0; i < ByteString.size(); i = i + this->CharByteStringLength)
            {
                ByteChunk = ByteString.substr(i,this->CharByteStringLength);
                CharacterSetIndex = std::bitset<std::numeric_limits<unsigned long>::digits>(ByteChunk).to_ulong();
                CharString += this->CharacterSet[CharacterSetIndex];
            }
            
            this->CSContainer->Add(CharString);
            
            if(i % 10000 == 0)
            {
                std::cout << i << std::endl;
            }
        }
    }
    
    std::string CSGenerator::Dec2bin(unsigned long n)
    {
        std::string res;
        res.reserve(this->CharByteStringLength * 8);
        
        while (n)
        {
            res.push_back((n & 1) + '0');
            n >>= 1;
        }

        while(res.size() < this->CharByteStringLength * 8)
        {
            res.append("0");
        }
        
        std::reverse(res.begin(), res.end());
        
        return res;
    };
    
    void CSGenerator::SetFilePath(std::string FilePath)
    {
        this->FilePath = FilePath;
    }
    
    void CSGenerator::SetNumberOfCodes(int NumberOfCodes)
    {
        this->NumberOfCodes = NumberOfCodes;
    }
}