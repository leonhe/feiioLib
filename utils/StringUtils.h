//
// Created by Yuanfei He on 15/4/8.
//


#ifndef __StringUtils_H_
#define __StringUtils_H_

#include "cocos2d.h"
#include <string>
namespace feiio
{
    struct StringUtils {
    /*分割字符串并返回到设置的容器中*/
    static cocos2d::ValueVector &split(const std::string &value,
            const std::string &flag,
            cocos2d::ValueVector &con);
};
}


#endif //__String_H_
