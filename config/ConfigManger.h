//
//  ConfigManger.h
//  feiio_libs
//
//  Created by Yuanfei He on 15-3-12.
//  Copyright (c) 2015年 Yuanfei He. All rights reserved.
//

#ifndef __feiio_libs__ConfigManger__
#define __feiio_libs__ConfigManger__

#include <stdio.h>
#include <string>
#include <map>
#include "config/ConfigFile.h"

namespace feiio {
  
enum ConfigType
{
    CSV,TXT
};
//配置文件工厂类初始化对配置文件类型解析
class ConfigFileManager
{
    
public:
    static ConfigFileManager *getInstance();
    static void deleteInstance();
    ConfigFile *initData(std::string &data,std::string name,ConfigType type);
    ~ConfigFileManager();
    ConfigFile *getConfByName(const std::string &name);
    void removeConf(const std::string &name);
    
private:
    static ConfigFileManager* _instance;
    std::map<std::string,ConfigFile*> _configes;
    
};
    
}
#endif 
