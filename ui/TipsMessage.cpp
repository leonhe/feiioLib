//
// Created by Yuanfei He on 15/4/24.
//

#include "TipsMessage.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

bool TipsMessage::init() {

   _text = Text::create("Test", "Arial", 36);
    _text->setColor(Color3B::BLACK);
//    _text->setSystemFontSize(36);
    addChild(_text);


    return true;
}

TipsMessage * TipsMessage::display() {
    auto text = TipsMessage::create();
    auto director = Director::getInstance();
    director->getRunningScene()->addChild(text);
    auto size=director->getVisibleSize();
    auto vec_target = cocos2d::Vec2(size.width*0.5,size.height*0.5);
    text->setPosition(vec_target-Vec2(0,50));

    text->setOpacity(0);

    auto moveTo = MoveTo::create(0.5, vec_target);

    Vector<FiniteTimeAction*> vecM;
    vecM.pushBack(Spawn::create(FadeIn::create(0.5),moveTo, nullptr));
    vecM.pushBack(DelayTime::create(0.5));
    vecM.pushBack(Spawn::create(FadeOut::create(0.5),MoveTo::create(0.3, vec_target+cocos2d::Vec2(0,50)),nullptr));
    vecM.pushBack(CallFuncN::create([](cocos2d::Node* node){
                node->removeFromParent();
    }));
    auto seq = Sequence::create(vecM);
    text->runAction(seq);



    return text;
}

void TipsMessage::setMessgae(const std::string &value) {
    _text->setString(value);
    _text->enableShadow();
    _text->enableOutline(Color4B::WHITE, 2);
}


void TipsMessage::setOpacity(GLubyte opacity) {
    Node::setOpacity(opacity);
    _text->setOpacity(opacity);
}
