//
// Created by Yuanfei He on 15/5/4.
//

#include "FacadeGame.h"

FacadeGame* FacadeGame::_instance = nullptr;


FacadeGame *FacadeGame::getInstance() {

    if(_instance== nullptr)
    {
        _instance = new FacadeGame();
        return _instance;
    }
    return _instance;
}


void FacadeGame::addSubjecte(feiio::Subject *model) {
    const char* name = model->getName();
    if(!this->isSubject(name))
    {
        model->retain();
        _modeles[model->getName()] = model;
    }
}

void FacadeGame::addController(feiio::Mediator *controller) {
    const char* name = controller->getName();
    if(!this->isController(name))
    {
        controller->retain();
        _controlles[controller->getName()] = controller;
    }
}

feiio::Subject *FacadeGame::getSubject(const char *name) {

    if(!this->isSubject(name))return nullptr;
    return _modeles[name];
}

feiio::Mediator *FacadeGame::getController(const char *name) {
    if(!this->isController(name)) return nullptr;
    return _controlles[name];
}

void FacadeGame::removeSubject(const char *name) {
    if(!this->isSubject(name)) return;
    _modeles[name]->release();
    _modeles.erase(name);
}


void FacadeGame::removeControler(const char *name) {
    if(!this->getController(name)) return;
    _controlles[name]->release();
    _controlles.erase(name);
}

bool FacadeGame::isSubject(const char *name) {

    return _modeles.find(name)!=_modeles.end();
}

bool FacadeGame::isController(const char *name) {
    return _controlles.find(name)!=_controlles.end();
}
