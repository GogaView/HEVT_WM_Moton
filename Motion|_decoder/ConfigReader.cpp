//
//  ConfigReader.cpp
//  Motion|_decoder
//
//  Created by MacBook on 16.04.17.
//  Copyright © 2017 kosa. All rights reserved.
//

#include "ConfigReader.hpp"
#include <fstream>


CConfigReader::CConfigReader(std::string file)
{
    _readFile(file);
}

void CConfigReader::_readFile(std::string strFile)
{
    std::ifstream file(strFile);
    
    char c[256];
    file.getline(c,256);
    file.getline(c,256);
    
    while(!file.eof())
    {

        
        st_inter_stract val;
        sscanf(c,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", &val.iFrame, &val.iW, &val.iH, &val.iX_curr, &val.iY_curr, &val.iV_mv, &val.iH_mv, &val.iRefIndex);
        
        file.getline(c,256);
        
        m_vData.push_back(val);
    }
}

std::vector<st_inter_stract> CConfigReader::getData()
{
    return m_vData;
}