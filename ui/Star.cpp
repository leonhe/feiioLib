//
//  Star.cpp
//  PopTouch
//
//  Created by Yuanfei He on 15/4/2.
//
//

#include <string>
#include <cmath>
#include <algorithm>
#include "ui/Star.h"
#include "cocos2d.h"

USING_NS_CC;

Star *Star::createWithFileAndNum(const std::string &enableFile, const std::string &disFile,int num)
{
    auto pStar = new (std::nothrow) Star;
    if (pStar && pStar->init(enableFile,disFile, num)) {
        pStar->autorelease();
        return pStar;
    }else{
        CC_SAFE_DELETE(pStar);
        return nullptr;
    }
}


bool Star::init(const std::string &enableFile, const std::string &disFile,int num)
{
    if (!Node::init()) return false;
    _starNum = num;
    auto openGLView = Director::getInstance()->getOpenGLView();
    auto textureCache = Director::getInstance()->getTextureCache();
    _enableTexture = textureCache->addImage(enableFile);
    _disableTexutre = textureCache->addImage(disFile);
    size= _enableTexture->getContentSize();
    for (int i=0; i<num; ++i)
    {
        auto sp = Sprite::createWithTexture(_disableTexutre);
        sp->setScale(openGLView->getScaleX(),openGLView->getScaleY());
        sp->setPosition(Vec2(i*_disableTexutre->getContentSize().width,0));
        addChild(sp);
        _starVec.pushBack(sp);
    }
    return true;
}


void Star::setEnableNum(int value)
{
    if (value>_starNum)
        value = _starNum;

    _enableNum = value;
    int index = 0;
    for (auto it = _starVec.begin(); it!=_starVec.end(); ++it)
    {
        auto sp = *it;
        if (index<value && sp->getTexture()!=_enableTexture) {
            sp->setTexture(_enableTexture);

        }
        index ++;
    }
}

void Star::setCenetScale(float cenScale, float nonal)
{
    if (_starNum%2==0) return;
    int val=::floor(_starNum/2);
    int index=0;
    cocos2d::Size lastWidth(0,0);
    cocos2d::Point pos;
    std::for_each(_starVec.begin(), _starVec.end(), [&](Sprite *p_Sp){
        float scaleVal = nonal;
        if (index==val)
        {
            scaleVal = cenScale;
        }
        this->_scaleValue = scaleVal;
        p_Sp->setScale(scaleVal);
        if (lastWidth.width>0) {
            p_Sp->setPositionX(pos.x+lastWidth.width);
        }
        lastWidth = p_Sp->getContentSize()*scaleVal;
        pos = p_Sp->getPosition();
        index++;
    });
    
}

const cocos2d::Size &Star::getContentSize() const
{
    return size;
}


float Star::getScale() const
{
    return _scaleValue;
}




