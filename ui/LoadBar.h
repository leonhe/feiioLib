//
// Created by Yuanfei He on 15/5/5.
//


#ifndef __LoadBar_H_
#define __LoadBar_H_

#include <string>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "LoadScene/LoadAssert.h"
#include <vector>
#include <functional>

class LoadBar : public cocos2d::Node ,public LoadCallBackDelegate{


    typedef  std::function<void(void)> CallBackFun;
public:
    bool initWithFile(const std::string &file);
    static LoadBar* createWithLoadBar(const std::string &file);
    void setProgressValue(int value);

    virtual void finish() override;

    virtual void progress(int value) override;
    ~LoadBar();

    void startLoad(const std::vector<std::string> &value);

    void setCallBackFun(const CallBackFun &fun);
private:
    cocos2d::Node* _rootNode;
    cocos2d::ui::LoadingBar* _loadBar;
    LoadAssert* _loadAsset;

    CallBackFun _callfun;
};


#endif //__LoadBar_H_
