//
//  ConfigManger.cpp
//  feiio_libs
//
//  Created by Yuanfei He on 15-3-12.
//  Copyright (c) 2015年 Yuanfei He. All rights reserved.
//

#include "ConfigManger.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

namespace feiio {
    
ConfigFileManager *ConfigFileManager::_instance = nullptr;

ConfigFileManager* ConfigFileManager::getInstance()
{
    if (ConfigFileManager::_instance==nullptr) {
        _instance = new ConfigFileManager();
    }
    return _instance;
}

ConfigFile *ConfigFileManager::initData(std::string &data, std::string name, ConfigType type)
{
    ConfigFile *conf;
    switch (type) {
        case CSV:
            conf = new ConfigCSVFile();
            break;
        default:
            std::cout<<"can't found type:"<<name<<std::endl;
            break;
    }
    
    if (conf && conf->initWithData(data)) {
        _configes[name] = conf;
        return conf;
    }else{
        delete conf;
        conf = nullptr;
    }
        return conf;
}

void ConfigFileManager::deleteInstance()
{
    delete _instance;
    _instance = nullptr;
}


ConfigFileManager::~ConfigFileManager()
{
    typedef map<string,ConfigFile*>::iterator m_iterator;
    m_iterator i = _configes.begin();
    for (; i!=_configes.end(); ++i) {
        delete i->second;
    }
    _configes.clear();
}


ConfigFile *ConfigFileManager::getConfByName(const std::string &name)
{
    return _configes[name];
}

void ConfigFileManager::removeConf(const std::string &name)
{
    delete _configes[name];
    _configes[name] = nullptr;
    auto it = _configes.find(name);
    _configes.erase(it);
}

    
}
