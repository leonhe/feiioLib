//
// Created by Yuanfei He on 15/4/8.
//


#ifndef __StringUtils_H_
#define __StringUtils_H_

#include "cocos2d.h"
#include <string>
namespace feiio
{
    class StringUtils {
	public:
		//split string return setting container
    static cocos2d::ValueVector &split(const std::string &value,const std::string &flag,cocos2d::ValueVector &con);
};
}


#endif //__String_H_
