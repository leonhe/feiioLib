//
//  probability.h
//  PopTouch
//
//  Created by Yuanfei He on 15/4/1.
//
//

#ifndef __PopTouch__probability__
#define __PopTouch__probability__

#include "cocos2d.h"
#include <map>
#include <random>
class Probabillty : public cocos2d::Ref
{

public:
    Probabillty()=default;
    Probabillty(int percentage);
    void initData(int num);
    
    bool isProbabillty();
private:
    const static int MAX_LEN=100;
    int _percentage;//长度
    int _buf[MAX_LEN]={0};
    std::default_random_engine _engier;
    
    
};


#endif /* defined(__PopTouch__probability__) */
