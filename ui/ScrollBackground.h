//
// Created by Yuanfei He on 15/5/13.
//


#ifndef __ScrollBackground_H_
#define __ScrollBackground_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class ScrollBackground : public cocos2d::Node{

public:
    virtual bool init() override;
    virtual void update(float delay);
    CREATE_FUNC(ScrollBackground);


private:
    cocos2d::Vector<cocos2d::Node*> _spVec;

    cocos2d::ui::ScrollView *_scrollCon;

    void scrollView(cocos2d::Ref *send, cocos2d::ui::ScrollView::EventType type);

    int _maxLen;
    int _scrollIndex;

    cocos2d::Node* _rootNode;
};


#endif //__ScrollBackground_H_
