//
// Created by Yuanfei He on 15/4/29.
//

#include "RadioCheckBox.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;


void RadioCheckBox::addButton(cocos2d::ui::Button *btn) {
    _btns.pushBack(btn);
    btn->addTouchEventListener(CC_CALLBACK_2(RadioCheckBox::callBackTouchEvent, this));
}

void RadioCheckBox::removeButton(cocos2d::ui::Button *btn) {
    btn->setTouchEnabled(false);
    btn->setEnabled(false);
    _btns.eraseObject(btn);

}

void RadioCheckBox::callBackTouchEvent(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type)
{
    auto btn = static_cast<cocos2d::ui::Button*>(ref);
    if(type==cocos2d::ui::Widget::TouchEventType::ENDED)
    {
        this->setBtnStates(btn, false);
        if(_callBackComplete){

            _callBackComplete(btn);
        }
    }
}

bool RadioCheckBox::initWithImage(const std::string &file) {

    _topImg = Sprite::createWithSpriteFrameName(file);
    if(!_topImg) return false;
    _topImg->setAnchorPoint(cocos2d::Vec2(0.5,0.5));
    _topImg->retain();
    _seletedBtn = nullptr;
    return true;
}

RadioCheckBox *RadioCheckBox::createWithImage(const std::string &file) {
    auto radio = new RadioCheckBox();
    if(radio && radio->initWithImage(file))
    {
        radio->autorelease();
        return radio;
    }else CC_SAFE_DELETE(radio);

    return nullptr;
}


void RadioCheckBox::setBtnStates(cocos2d::ui::Button *btn, bool isSeleted) {

    if(_seletedBtn!=nullptr)
    {
        _seletedBtn->setEnabled(true);
        _seletedBtn->setBright(true);
        _seletedBtn->setTouchEnabled(true);
        _topImg->removeFromParent();
    }

    const cocos2d::Size btnSize = btn->getContentSize();
    const cocos2d::Size imgSize = _topImg->getContentSize();
    float scaleX= btnSize.height/imgSize.width;

    _topImg->setScale(scaleX);
    _topImg->setPosition(btnSize.width*0.5,btnSize.height*0.5);
    _seletedBtn = btn;
    btn->setEnabled(!isSeleted);
    btn->setBright(isSeleted);
    btn->setTouchEnabled(isSeleted);
    btn->addChild(_topImg);

    CCLOG("%d",isSeleted);

}

RadioCheckBox::~RadioCheckBox() {
    _topImg->release();
}

void RadioCheckBox::setCallBackComplete(RadioCheckBox::ccCallBackCheckBox const &fun) {
    _callBackComplete = fun;
}
