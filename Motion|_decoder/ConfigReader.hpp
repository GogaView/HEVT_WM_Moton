//
//  ConfigReader.hpp
//  Motion|_decoder
//
//  Created by MacBook on 16.04.17.
//  Copyright © 2017 kosa. All rights reserved.
//

#ifndef ConfigReader_hpp
#define ConfigReader_hpp

#include <stdio.h>
#include <vector>
#include <string>

struct st_inter_stract
{
    int iFrame;
    
    int iW;
    int iH;
    
    int iX_curr;
    int iY_curr;
    
    int iV_mv;
    int iH_mv;
    
    int iRefIndex;
};

class CConfigReader
{
    std::vector<st_inter_stract>                m_vData;
    
public:
                                                CConfigReader(std::string);
    
private:
    void                                        _readFile(std::string);
    
public:
    std::vector<st_inter_stract>                getData();
    
    
    
};

#endif /* ConfigReader_hpp */
