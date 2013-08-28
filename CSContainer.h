//
//  CSContainer.h
//  CharacterSetsGenerator
//
//  Created by Andrei Ionescu on 8/26/13.
//  Copyright (c) 2013 Andrei Ionescu. All rights reserved.
//

#ifndef __CharacterSetsGenerator__CSContainer__
#define __CharacterSetsGenerator__CSContainer__

#include <iostream>
#include <vector>

namespace NCSGenerator
{
    class CSContainer
    {
    private:
        std::vector<std::string> _CSContainer;
    public:
        CSContainer();
        void Add(std::string CharacterSet);
        std::vector<std::string> GetContainer();
        static const unsigned int BUFFER = 2000;
        static const unsigned int CHARSETSIZE = 8;
    };
}
#endif /* defined(__CharacterSetsGenerator__CSContainer__) */
