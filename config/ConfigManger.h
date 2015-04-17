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
#include "ConfigFile.h"
/*
 *auto fileContent = FileUtils::getInstance()->getStringFromFile("Test.csv");
 *auto conf=ConfigFileManager::getInstance();
 *conf->initData(fileContent, "Test", ConfigType::CSV);
 auto test = ConfigFileManager::getInstance()->getConfByName("Test");
 vector<std::string> *data=test->getValueByFlag("id",2);
 
 string title;
 test->getValue(data, "des",&title);
 CCLOG("%s",title.c_str());
 int len =test->length();
 
 conf->removeConf("Test");
   ConfigFileManager::deleteInstance();
 */
namespace feiio {
  
enum ConfigType
{
    CSV
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
#endif /* defined(__feiio_libs__ConfigManger__) */
