//
//  main.cpp
//  Motion|_decoder
//
//  Created by MacBook on 16.04.17.
//  Copyright © 2017 kosa. All rights reserved.
//

#include <iostream>
#include "ConfigReader.hpp"
#include "MotionDecoder.hpp"
#include "print_matrix.h"

//#define LOG



int main(int argc, const char * argv[])
{
    
    CConfigReader configReader("/Users/macbook/Library/Developer/Xcode/DerivedData/HM_origin-abadnxruhqepfhdfonruobcflnzj/Build/Products/Debug/Inter_pos");
    CMotionDecoder motionDecoder("/Users/macbook/Library/Developer/Xcode/DerivedData/HM_origin-abadnxruhqepfhdfonruobcflnzj/Build/Products/Debug/bus.yuv");
    
    
    auto vData = configReader.getData();
    for(auto it = vData.begin(); it != vData.end(); ++it )
    {
        auto currData = motionDecoder.getCoordinats(it->iFrame, it->iX_curr, it->iY_curr, it->iW, it->iH);
        auto mvData = motionDecoder.getCoordinats(it->iRefIndex, it->iX_curr + it->iH_mv/4 , it->iY_curr + it->iV_mv/4, it->iW, it->iH);

#ifdef LOG
        print_mat("Curr data", currData, it->iW, it->iH);
        print_mat("MV data", mvData, it->iW, it->iH);
#endif
        auto psnr = motionDecoder.psnr(currData, mvData, it->iW, it->iH);
        auto isEqual = motionDecoder.isEqual(currData, mvData, it->iW, it->iH);
        int i = 0;
        
    }
    
    
    
    return 0;
}
