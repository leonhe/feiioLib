//
//  Observer.h
//  PopTouch
//
//  Created by Yuanfei He on 15-3-24.
//
//

#ifndef __PopTouch__Observer__
#define __PopTouch__Observer__

#include <list>
#include <map>
#include <unordered_map>
#include <exception>
#include <functional>
#include <string>
#include "cocos2d.h"

namespace feiio {
    
    class Observer;
    //主体
    class Subject :public cocos2d::Ref
    {
        
        typedef std::list<Observer*>::iterator observer_iterator;
        
        typedef std::function<void(void)> observerCallBack;
        
    public:
        virtual ~Subject();
        void addObserver(Observer *observer);
        void removeObserver(Observer *observer);
        
        void addObserver(const char *key,observerCallBack &fun);
        void removeObserver(const char *key);
    private:
        bool hasObserver( Observer *observer);
        std::list<Observer*> _observers;
//        std::map<const char*,std::function<void(void)>> _map;
        std::multimap<const char*, observerCallBack> _map;
    protected:
        void sendNotification();
        void sendNotification(const char *key);
        void sendCCNotification(const std::string &value,void *data=nullptr);
    };
    
    //观察者
    class Observer:public cocos2d::Ref
    {
    public:
       virtual void updateData()=0;
        virtual Subject *getModel()=0;
    };
};

#endif /* defined(__PopTouch__Observer__) */
