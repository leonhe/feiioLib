//
//  ViewManager.h
//  PopTouch
//
//  Created by Yuanfei He on 15-3-24.
//
//

#ifndef __PopTouch__ViewManager__
#define __PopTouch__ViewManager__

#include <stdio.h>
#include "cocos2d.h"
#include "Mediator.h"
#include "Frameworks.h"
#include "Observer.h"
#include <memory>
namespace feiio {
    class View {
    public:
        View(feiio::Mediator *_mediator = nullptr);

        virtual ~View();

        void setController(feiio::Mediator *value);

        virtual feiio::Subject *getModel();

        void setModel(feiio::Subject *value);

    protected:
        feiio::Mediator *_controller;
        feiio::Subject *_model;

    };
}
class ViewManager : public cocos2d::Layer,public feiio::View
{
public:
    ViewManager(feiio::Mediator *_mediator=nullptr): feiio::View::View(_mediator){};
    void onEnter() override;
    void onExit() override;
    void onEnterTransitionDidFinish() override;
    void onExitTransitionDidStart() override;


};

#endif /* defined(__PopTouch__ViewManager__) */
