//
//  probability.cpp
//  PopTouch
//
//  Created by Yuanfei He on 15/4/1.
//
//

#include "probability.h"
#include <random>

Probabillty::Probabillty(int percentage):
_percentage(percentage)
{
    initData(_percentage);
}


void Probabillty::initData(int num)
{
    ::memset(&_buf, 0, MAX_LEN);
    _percentage = num;
     std::default_random_engine engier;
    for (int i=0; i<MAX_LEN; ++i)
    {
        _buf[i] = (i<_percentage)?1:0;
    }
}

bool Probabillty::isProbabillty()
{
    
    bool isExecute = true;
    do
    {
        std::uniform_int_distribution<int> distribution(0,MAX_LEN-1);
        int  index = distribution(_engier);
        int res= _buf[index];
        if (res!=-1)
        {
            _buf[index] = -1;
            isExecute  =false;
            return res;
        }
        
    }while (isExecute);
    return false;
}