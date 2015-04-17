//
//  ConfigFile.cpp
//  feiio_libs
//
//  Created by Yuanfei He on 15/2/28.
//  Copyright (c) 2015年 Yuanfei He. All rights reserved.
//

#include "ConfigFile.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

namespace feiio {

    ConfigFile::~ConfigFile() {

    }

//-----------------ConfigFile
    bool ConfigFile::initWithData(std::string &data) {
        return true;
    }

    vector<string> *ConfigFile::getValueByFlag(const std::string &name, const std::string &value) {

        vector<string> *result = nullptr;

        int index = getFlagIndex(name);
        typedef vector<vector<string>>::iterator v_iterator;
        v_iterator i = _value.begin();
        for (; i != _value.end(); ++i) {
            auto valueList = *i;
            if (valueList.at(index) == value) {
                result = &(*i);
                break;
            }
        }
        return result;
    }


    vector<string> *ConfigFile::getValueByFlag(const std::string &name, const int value) {

        vector<string> *result = nullptr;

        int index = getFlagIndex(name);
        typedef vector<vector<string>>::iterator v_iterator;
        v_iterator i = _value.begin();
        for (; i != _value.end(); ++i) {
            auto valueList = *i;
            string tmpstr = valueList.at(index);
            if (atoi(tmpstr.c_str()) == value) {
                result = &(*i);
                break;
            }
        }
        return result;
    }


    bool ConfigFile::getValue(std::vector<std::string> *data, const std::string &name, void *value) {
        int index = getFlagIndex(name);
        bool result = false;

        if (index > -1) {
            string type = _type.at(index);
            string val = *(data->begin() + index);

            if (type == "int") {
                int *pInt = static_cast<int *>(value);
                *pInt = atoi(val.c_str());
                result = true;
            } else if (type == "string") {
                string *pStr = static_cast<string *>(value);
                *pStr = val;
                result = true;
            } else if (type == "double") {
                double *pDouble = static_cast<double *>(value);
                *pDouble = atof(val.c_str());
                result = true;
            } else if (type == "long") {
                float *pFloat = static_cast<float *>(value);
                *pFloat = atol(val.c_str());
                result = true;
            }else {
                throw  logic_error("为找到数据类型!");
            }
        }
        return result;
    }


    int ConfigFile::getFlagIndex(const std::string &value) {
        typedef vector<string>::iterator v_iterator;
        v_iterator i = _flag.begin();
        int index = 0;
        int result = -1;
        for (; i != _flag.end(); ++i) {
            std::string &f_str = *i;
            if (f_str == value) {
                result = index;
                break;
            }
            index++;
        }
        return result;
    }


//-----------------ConfigCSVFile--
    bool ConfigCSVFile::initWithData(std::string &data) {

        istringstream str(data);
        string tmpStr;

        vector<vector<string>> vec;


        int line = 0;

        while (std::getline(str, tmpStr,'\r')) {

            vector<string> value; //临时值列表
            vector<string> *pList = nullptr;
            if (line == 0) {
                pList = &_flag;
            } else if (line == 1) {
                pList = &_type;
            } else {
                pList = &value;
            }


            resolveString(pList, &tmpStr);
            if (line > 1) {
                _value.push_back(value);
                size++;
            }
            line++;
        }


        return true;
    }

    void ConfigCSVFile::resolveString(vector<string> *value, string *source) {
        string::size_type offset = 0;
        string::size_type pos = 0;

        while (pos != string::npos) {
            pos = source->find(";", pos);
            auto str = source->substr(offset, pos - offset);
            value->push_back(str);
            if (pos == string::npos) break;
            pos++;
            offset = pos;
        }

    }


    std::vector<std::string> *ConfigFile::getValueByIndex(std::size_t index) {
        if (index > size) return nullptr;
        return &(_value[index]);
    }
};