//
// Created by Yuanfei He on 15/4/24.
//


#ifndef __Tips_H_
#define __Tips_H_

#include <string>
#include "cocos2d.h"
#include "ui/CocosGUI.h"


//提示面板
class Tips:public cocos2d::Node {

public:
    bool initWithName(const std::string &value);
    static Tips* createWithNode(const std::string &value);
    void setString(const std::string &value);
    static Tips* getInstance(const std::string &value);
    static Tips* getInstance();
    static Tips * display(const std::string &filename);
    static void hide();

private:
    cocos2d::Node* _rootNode;
    cocos2d::ui::Text* _txt;
    cocos2d::ui::ImageView* _bg;

    static Tips* _instance;

    cocos2d::Label* _contentLab;
};


#endif //__Tips_H_
