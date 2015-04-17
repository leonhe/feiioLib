//
//  ViewManager.cpp
//  PopTouch
//
//  Created by Yuanfei He on 15-3-24.
//
//

#include "ViewManager.h"
#include "cocos2d.h"
#include "Frameworks.h"
#include "Observer.h"
#include <memory>
USING_NS_CC;
using namespace feiio;

namespace feiio {

    View::View(feiio::Mediator *_mediator) {

        this->setController(_mediator);
    }

    void View::setModel(Subject *value)
    {
        _model = value;
        _model->retain();

    }

    void View::setController(feiio::Mediator *value)
    {
        if (value!= nullptr) {
            _controller = value;
            _controller->setViewCompoment(this);
            _controller->retain();
        }
    }

    Subject *View::getModel()
    {
        return _model;
    }

    View::~View()
    {
        if (_controller) {
            _controller->end();
            _controller->release();
        }

        if(_model)
        {
            _model->release();
        }
    }

}

void ViewManager::onEnter()
{
    Layer::onEnter();
    if (_controller)
    {
        _controller->start();
    }

}



void ViewManager::onExit()
{
    Layer::onExit();

}

void ViewManager::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
   
}

void ViewManager::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    
    
}


