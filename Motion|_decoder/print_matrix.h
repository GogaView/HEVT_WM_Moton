//
//  Header.h
//  Motion|_decoder
//
//  Created by MacBook on 16.04.17.
//  Copyright © 2017 kosa. All rights reserved.
//

#ifndef Header_h
#define Header_h


#include <string>
#include <iostream>

inline void print_mat(std::string strText, int** pData, int W, int H)
{
    std::cout << strText << std::endl;
    
    for(int i = 0; i != H; ++i)
    {
        for(int j = 0; j != W; ++j)
        {
            std::cout << pData[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

#endif /* Header_h */
