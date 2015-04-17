//
//  Observer.cpp
//  PopTouch
//
//  Created by Yuanfei He on 15-3-24.
//
//

#include "Observer.h"
#include <algorithm>
#include <list>
#include <cassert>
#include <exception>
#include <map>
#include <functional>
#include "cocos2d.h"

namespace feiio {
    
    using namespace std;
    
    USING_NS_CC;
    
    Subject::~Subject()
    {
        _map.clear();
    }
    
    void Subject::sendNotification()
    {
        for_each(_observers.begin(), _observers.end(), [&](Observer *_observer){
            _observer->updateData();
        });
     
    }
    
    void Subject::sendNotification(const char *key)
    {
        if(_map.size()<=0)return;
        
            for_each(_map.begin(), _map.end(), [key](pair<const char *, std::function<void()>> value){
            if(::strcmp(key, value.first)==0)
            {
                (value.second)();
            }
            
        });
        
    }
    
    void Subject::addObserver(feiio::Observer *observer)
    {
       
         if(hasObserver(observer))
         {
//             throw runtime_error("Observer already exisite!");
             return;
         }
        _observers.push_back(observer);
    }
    
    
    void Subject::addObserver(const char *key, observerCallBack &fun)
    {
        auto funs = static_cast<observerCallBack>(fun);
        _map.insert(pair<const char*, observerCallBack>(key, funs));
    }
    
    
    void Subject::removeObserver(feiio::Observer *observer)
    {
        auto it = find(_observers.begin(), _observers.end(), observer);
        if (!hasObserver(observer)) return;
        _observers.erase(it);
    }
    
    void Subject::removeObserver(const char *key)
    {
       
        auto it =  _map.find(key);
        if (it==_map.end()) return;
        _map.erase(it);
    }
    
    
    
    bool Subject::hasObserver( Observer *observer)
    {
        auto it = std::find(_observers.begin(), _observers.end(), observer);
        return it!=_observers.end();
    }
    
    void Subject::sendCCNotification(const std::string &value,void *data)
    {
        auto dispatch=Director::getInstance()->getEventDispatcher();
        dispatch->dispatchCustomEvent(value,data);
    }
    
    
    
}