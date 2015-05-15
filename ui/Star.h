//
//  Star.h
//  PopTouch
//
//  Created by Yuanfei He on 15/4/2.
//
//

#ifndef __PopTouch__Star__
#define __PopTouch__Star__

#include <string>
#include "cocos2d.h"


class Star :public cocos2d::Node
{
    
public:
    Star():_starNum(0),_enableNum(0){};
    static Star *createWithFileAndNum(const std::string &enableFile, const std::string &disFile,int num);
    bool init(const std::string &enableFile, const std::string &disFile,int num);
    //设置启用图标数量
    void setEnableNum(int value);
    //设置区分中间图标和周围图标的大小
    void setCenetScale(float cenScale,float nonal);
    
    virtual const cocos2d::Size& getContentSize() const;
    
    virtual float getScale() const;
private:
    int _starNum,_enableNum;
    cocos2d::Vector<cocos2d::Sprite*> _starVec;
    
    cocos2d::SpriteFrame *_enableTexture,
                        *_disableTexutre;
    
    cocos2d::Size size;
    
    float _scaleValue;
};



#endif
