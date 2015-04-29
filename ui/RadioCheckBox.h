//
// Created by Yuanfei He on 15/4/29.
//


#ifndef __RadioCheckBox_H_
#define __RadioCheckBox_H_

#include <string>
#include <functional>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class RadioCheckBox : public cocos2d::Ref {

    typedef std::function<void(cocos2d::Ref* ref)> ccCallBackCheckBox;

public:
    bool initWithImage(const std::string &file);
    static RadioCheckBox* createWithImage(const std::string &file);
    void addButton(cocos2d::ui::Button *btn);
    void removeButton(cocos2d::ui::Button *btn);
    void setBtnStates(cocos2d::ui::Button* btn,bool isSeleted);
    ~RadioCheckBox();
    void setCallBackComplete(const ccCallBackCheckBox &fun);
private:
    cocos2d::Vector<cocos2d::ui::Button*> _btns;
    cocos2d::Sprite* _topImg;
    cocos2d::ui::Button* _seletedBtn;
    void callBackTouchEvent(cocos2d::Ref* ref,cocos2d::ui::Widget::TouchEventType type);

    ccCallBackCheckBox _callBackComplete;

};


#endif //__RadioCheckBox_H_
