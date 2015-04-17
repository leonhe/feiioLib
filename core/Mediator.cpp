//
//  Mediator.cpp
//  PopTouch
//
//  Created by Yuanfei He on 15-3-24.
//
//

#include "Mediator.h"
#include "Frameworks.h"

namespace feiio {

    void Mediator::setViewCompoment(View *node) {
        _view = node;
    }

    View *Mediator::getViewCompoment() {
        return _view;
    }

    void Mediator::updateData(const char *type, cocos2d::Ref *data) {

    }

    void Mediator::updateData() {

    }

    void Mediator::start() {

    }

    void Mediator::end() {

    }

    feiio::Subject *Mediator::getModel() {
        return _model;
    }


    Mediator::Mediator(Subject *m):_model(m){
        if(_model)
            _model->retain();
    }

    Mediator::~Mediator() {
        if(_model)
            _model->release();

    }
}
