//
// Created by Yuanfei He on 15/4/23.
//


#ifndef __ConfSerialization_H_
#define __ConfSerialization_H_

#include <vector>
#include "config/ConfigManger.h"
#include "Conf.h"
#include "cocos2d.h"

template<typename T>
class ConfSerialization {
    const char *_name;
    std::vector<T*> _data;
public:
    ConfSerialization(const char *n) : _name(n) {
    };

    void init() {
//         auto data = Conf::loadConf(_name);
//        data->serialization();


    }

};


#endif //__ConfSerialization_H_
