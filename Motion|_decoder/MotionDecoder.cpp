//
//  MotionDecoder.cpp
//  Motion|_decoder
//
//  Created by MacBook on 16.04.17.
//  Copyright © 2017 kosa. All rights reserved.
//

#include "MotionDecoder.hpp"

#include <string>
#include <math.h>


#define MAX (255*255)

CMotionDecoder::CMotionDecoder(std::string strFile)
{
    _readFrames(strFile);
}

void CMotionDecoder::_readFrames(std::string strFile)
{
    FILE* f;
    f = fopen(strFile.c_str(), "rb");
    
    unsigned char luma1 = '\0';
    
    // read all data
    for (int fr = 0; (fr < FRAME); fr++)
    {
        int** b = new int* [size1];
        for (int i = 0; i < size1; i++)
        {
            b[i] = new int [size2];
        }
        
        
        // Y
        for (int i = 0; i < size2; i++)
            for (int j = 0; j < size1; j++)
            {
                fread(&luma1,  1, 1, f);
                b[i][j] = luma1;
            }
        
        // U
        for (int i = 0; i < size2/2; i++)
            for (int j = 0; j < size1/2; j++)
            {
                fread(&luma1,  1, 1, f);
            }
        
        // V
        for (int i = 0; i < size2/2; i++)
            for (int j = 0; j < size1/2; j++)
            {
                fread(&luma1,  1, 1, f);
            }
        
        
        m_vVideo.push_back(b);
    }
}

int** CMotionDecoder::getFrame(int iFrame)
{
    return m_vVideo[iFrame];
}

int** CMotionDecoder::getCoordinats(int iFrame, int X, int Y, int W, int H)
{
    auto pFrame = getFrame(iFrame);
    
    int** Block = new int* [H];
    for (int h = 0; h < H; h++)
    {
        Block[h] = new int [W];
    }
    
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            Block[h][w] = pFrame[Y + h ][X + w];
        }
    }
    
    return Block;
    
}

double CMotionDecoder::psnr(int** frame1, int** frame2, int x, int y)
{
    double MSE = 0.0;
    double MSEtemp = 0.0;
    double psnr = 0.0;
    
    
    //Calculate MSE
    for(int i =0; i<y; i++)
    {
        for(int j =0; j<x; j++)
        {
            MSEtemp = fabs(frame1[i][j]-frame2[i][j]);
            MSE += MSEtemp * MSEtemp;
        }
    }
    
    MSE /= x*y;
    
    //Avoid division by zero
    if(MSE==0)
        return 99.0;
    
    //The PSNR
    psnr = 10 * log10(MAX/MSE);
    
    //Thats it.
    return psnr;
}

bool CMotionDecoder::isEqual(int** frame1, int** frame2, int x, int y)
{
    for(int i =0; i<y; i++)
    {
        for(int j =0; j<x; j++)
        {
            if(frame1[i][j] != frame2[i][j])
                return false;
        }
    }
    
    return true;
}
