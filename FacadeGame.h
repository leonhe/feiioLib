//
// Created by Yuanfei He on 15/5/4.
//


#ifndef __FacadeGame_H_
#define __FacadeGame_H_
#include "Observer.h"
#include "Mediator.h"

#include <map>

class FacadeGame {
   static FacadeGame* _instance;
    std::map<const char*,feiio::Subject*> _modeles;
    std::map<const char*,feiio::Mediator*> _controlles;
public:
    static FacadeGame* getInstance();

    void addSubjecte(feiio::Subject* model);
    void addController(feiio::Mediator* controller);

    feiio::Subject* getSubject(const char* name);
    feiio::Mediator* getController(const char* name);

    void removeSubject(const char* name);
    void removeControler(const char* name);

    bool isSubject(const char* name);
    bool isController(const char* name);

};


#endif //__FacadeGame_H_
