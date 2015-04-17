//
//  Command.h
//  PopTouch
//
//  Created by Yuanfei He on 15-3-31.
//
//

#ifndef PopTouch_Command_h
#define PopTouch_Command_h
#include "cocos2d.h"


namespace feiio {
    
    class Command : public cocos2d::Ref
    {
    public:
        virtual void execute()=0;
    };

}

#endif
