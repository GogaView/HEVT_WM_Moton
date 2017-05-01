//
//  MotionDecoder.hpp
//  Motion|_decoder
//
//  Created by MacBook on 16.04.17.
//  Copyright © 2017 kosa. All rights reserved.
//

#ifndef MotionDecoder_hpp
#define MotionDecoder_hpp

#include <stdio.h>
#include <vector>

#define FRAME 25
#define size2 288
#define size1 352

class CMotionDecoder
{
    std::vector<int**>      m_vVideo;
    
    
    
public:
                            CMotionDecoder(std::string);
    
private:
    void                    _readFrames(std::string);
    
public:
    int**                   getFrame(int);
    int**                   getCoordinats(int iFrame, int X, int Y, int W, int H);
    
    double                  psnr(int** frame1, int** frame2, int x, int y);
    bool                    isEqual(int** frame1, int** frame2, int x, int y);
};



#endif /* MotionDecoder_hpp */
