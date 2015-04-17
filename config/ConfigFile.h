//
//  ConfigFile.h
//  feiio_libs
//
//  Created by Yuanfei He on 15/2/28.
//  Copyright (c) 2015年 Yuanfei He. All rights reserved.
//

#ifndef __feiio_libs__ConfigFile__
#define __feiio_libs__ConfigFile__

#include <string>
#include <vector>
#include <tuple>

namespace feiio {
 
//抽象配置文件接口
class ConfigFile
{
public:
    ConfigFile():size(0){};
    virtual ~ConfigFile();
    //返回从参数数据初始化配置文件是否成功
    virtual bool initWithData(std::string &data);
    std::vector<std::string> *getValueByFlag(const std::string &name,const std::string &value);
    std::vector<std::string> *getValueByFlag(const std::string &name,const int value);
    void resolveString(std::vector<std::string> *value,std::string *source);
    
    bool getValue(std::vector<std::string> *data,const std::string &name,void *value);
    
    inline int length(){return size;};
    //根据索引返回值
    std::vector<std::string> *getValueByIndex(std::size_t index);
    
protected:
//    std::vector<DATA*>_basicData;
    std::vector<std::string> _flag;
    std::vector<std::string> _type;
    std::vector<std::vector<std::string>> _value;
    
    int getFlagIndex(const std::string &value);
    int size;
};

//解析CSV文件格式
class ConfigCSVFile :public ConfigFile
{
public:
    bool initWithData(std::string &data);
    void resolveString(std::vector<std::string> *value,std::string *source);
};
    
}



#endif /* defined(__feiio_libs__ConfigFile__) */
