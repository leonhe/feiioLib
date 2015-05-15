//
// Created by Yuanfei He on 15/4/24.
//


#include "Tips.h"

#include <string>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;

using namespace cocos2d::ui;
using std::string;
Tips* Tips::_instance = nullptr;



Tips *Tips::createWithNode(const string &name) {

    auto tips = new Tips;
    if(tips && tips->initWithName(name))
    {
        tips->autorelease();
        return tips;
    }else{
        delete tips;
        tips = nullptr;
    }
    return nullptr;
}

void Tips::setString(const std::string &value) {
    _contentLab->setString(value);
    auto txt_contentSize = _contentLab->getContentSize();
    auto bg_contentSize = _bg->getContentSize();

    if(txt_contentSize.width>400)
    {

        _contentLab->setWidth(400);
    }

    float offsetW = bg_contentSize.width*0.1;
    float offsetH = 100;
    float w_val = bg_contentSize.width;
    txt_contentSize = _contentLab->getContentSize();
    CCLOG("%f %f",txt_contentSize.width,txt_contentSize.height);


    if(txt_contentSize.width>w_val)
    {
       w_val= txt_contentSize.width+ offsetW;
    }
    float  h_val = bg_contentSize.height;
    if(txt_contentSize.height<h_val)
    {
        h_val = txt_contentSize.height+offsetH;
    }

    _bg->setContentSize(cocos2d::Size(w_val,h_val));
    this->setContentSize(_bg->getContentSize());
    _contentLab->setPosition(cocos2d::Vec2(_bg->getPositionX()+w_val*0.5, h_val*0.55));
}


Tips *Tips::getInstance() {

    if(_instance== nullptr)
    {
        _instance = Tips::create();
        return _instance;
    }
    return _instance;

}

bool Tips::initWithName(const std::string &value) {

    _rootNode = CSLoader::getInstance()->createNodeWithFlatBuffersFile(value);
    _bg = static_cast<ImageView*>(_rootNode->getChildByName("bg"));
    addChild(_rootNode);
    auto contextSize = _rootNode->getContentSize();
    this->setContentSize(_bg->getContentSize());

    _contentLab = Label::create();
    _contentLab->setAnchorPoint(cocos2d::Vec2(0.5,1));
    _contentLab->setSystemFontSize(24.0f);
    _contentLab->setAlignment(TextHAlignment::LEFT);
    addChild(_contentLab);

    return true;
}

Tips * Tips::display(const std::string &filename) {

    if(!Tips::_instance)
    {
        auto tips = Tips::createWithNode(filename);
//        tips->initWithName(filename);
        tips->setAnchorPoint(Vec2(0,1));
        Director::getInstance()->getRunningScene()->addChild(tips);
        Tips::_instance = tips;

    }
    return Tips::_instance;
}

void Tips::hide() {
    if(Tips::_instance)
    {
        auto tips = Tips::_instance;
        tips->removeFromParent();
        Tips::_instance= nullptr;
    }

}

