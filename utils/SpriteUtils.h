//
// Created by Yuanfei He on 15/4/9.
//


#ifndef __SpriteUtils_H_
#define __SpriteUtils_H_

#include "cocos2d.h"

class SpriteUtils {
public:
    static void addGray(cocos2d::Node* sp);
    static void removeGray(cocos2d::Node* sp);
    static void addBlack(cocos2d::Node* sp);

    static void setSwallowTouches(cocos2d::Node *layer, bool isRemove);
};


#endif //__SpriteUtils_H_
