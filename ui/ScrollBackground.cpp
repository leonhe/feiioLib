//
// Created by Yuanfei He on 15/5/13.
//

#include "ScrollBackground.h"
#include <cmath>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;


const static int MAX_HEIGHT=10;
const static int IMAGE_LEN = 5;
static char* IMAGES_PATH[IMAGE_LEN]={"bg/map01.jpg","bg/map02.jpg","bg/map03.jpg","bg/map04.jpg","bg/map05.jpg"};
bool ScrollBackground::init() {

    if(!Node::init())
        return false;


    _rootNode = CSLoader::getInstance()->createNodeWithFlatBuffersFile("Layer.csb");
    auto visiableSize = Director::getInstance()->getVisibleSize();
    _scrollCon = ScrollView::create();
    _scrollCon->setBounceEnabled(false);
    _scrollCon->setContentSize(cocos2d::Size(visiableSize.width,visiableSize.height));

    _scrollCon->setDirection(ui::ScrollView::Direction::VERTICAL);
    addChild(_scrollCon);


    _maxLen = 3;

    for (int i = 0; i < IMAGE_LEN; ++i) {
        char* img_name = IMAGES_PATH[i];
        auto node = Node::create();
        node->setPosition(0, visiableSize.height*i);
        _scrollCon->addChild(node);

        auto sp = Sprite::create(img_name);
        sp->setAnchorPoint(cocos2d::Vec2(0,0));
        sp->setName(img_name);
        node->addChild(sp);
        char buf[20]={0};
        sprintf(buf, "gateItem_%d",i);

        auto gateItem = _rootNode->getChildByName(buf);
        CCASSERT(gateItem, "没有找到关卡相应的点UI");
            node->addChild(gateItem);
        _spVec.pushBack(node);
    }
    _scrollCon->setInnerContainerSize(cocos2d::Size(visiableSize.width,visiableSize.height*_maxLen));
//    _scrollCon->jumpToPercentVertical(1.0f);
    _scrollCon->scrollToBottom(0.1f, false);
    _scrollCon->jumpToBottom();
//    this->scheduleUpdate();

    _scrollCon->addEventListener(CC_CALLBACK_2(ScrollBackground::scrollView,this));


    return true;
}

void ScrollBackground::update(float delay)
{

}

void ScrollBackground::scrollView(cocos2d::Ref *send, cocos2d::ui::ScrollView::EventType type) {
    if(type==cocos2d::ui::ScrollView::EventType::SCROLLING)
    {
        auto pos= _scrollCon->getInnerContainer()->getPosition();
        auto visiableSize = Director::getInstance()->getVisibleSize();

        if(1-_maxLen!=pos.y/visiableSize.height)
        {
            float offsetVal=::fabs(pos.y);

            int value=abs(pos.y/visiableSize.height);

            int offset = value%IMAGE_LEN;
            auto sp = _spVec.at(offset);
            sp->setPositionY(value*visiableSize.height);
            auto pos = sp->getPosition();
                int preIndex = (offset-1>=0)?offset-1:IMAGE_LEN-1;
                auto preSp = _spVec.at(preIndex);
                preSp->setPositionY(pos.y-visiableSize.height);

                int nextIndex = (offset+1<IMAGE_LEN)?offset+1:0;
                auto nextSp = _spVec.at(nextIndex);
                nextSp->setPositionY(pos.y+visiableSize.height);

        }

    }
}
