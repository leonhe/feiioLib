//
// Created by Yuanfei He on 15/4/24.
//


#ifndef __TipsMessage_H_
#define __TipsMessage_H_

#include <string>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class TipsMessage:public cocos2d::Node {
public:
    virtual bool init() override;
    CREATE_FUNC(TipsMessage);
    static TipsMessage * display();

    void setMessgae(const std::string &value);

    virtual void setOpacity(GLubyte opacity) override;

private:
    cocos2d::Label* _text;
};


#endif //__TipsMessage_H_
