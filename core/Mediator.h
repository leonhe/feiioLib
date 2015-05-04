//
//  Mediator.h
//  PopTouch
//
//  Created by Yuanfei He on 15-3-24.
//
//

#ifndef __PopTouch__Mediator__
#define __PopTouch__Mediator__

#include <stdio.h>
#include "Frameworks.h"
#include "cocos2d.h"

namespace feiio {


class View;

class Mediator : public feiio::Observer,public cocos2d::Ref
{
    
public:
    Mediator(feiio::Subject *m=nullptr);
    ~Mediator();
    virtual void start();
    virtual void end();
    void setViewCompoment(View *node);
    virtual View *getViewCompoment();
    
    virtual void update() override;
    void updateData(const char *key, cocos2d::Ref *data = nullptr);
    
    virtual feiio::Subject *getModel() override;
    virtual const char* getName() const{ return _name;};
protected:
    feiio::Subject *_model;
    View *_view;
    const char *_name;
};
    
}

#endif 
