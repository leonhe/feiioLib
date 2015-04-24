//
// Created by Yuanfei He on 15/4/9.
//

#include "utils/SpriteUtils.h"
#include "cocos2d.h"

USING_NS_CC;

void SpriteUtils::addGray(cocos2d::Node* sp)
{
//    do
//    {
       GLchar* pszFragSource =
                "#ifdef GL_ES \n \
                 precision mediump float; \n \
                 #endif \n \
                 varying vec2 v_texCoord; \n \
                 varying vec4 v_fragmentColor; \n \
                 void main(void) \n \
                 { \n \
                 // Convert to greyscale using NTSC weightings \n \
                 vec4 col = v_fragmentColor*texture2D(CC_Texture0, v_texCoord); \n \
                 float grey = dot(col.rgb, vec3(0.299, 0.587, 0.145)); \n \
                 gl_FragColor = vec4(grey, grey, grey, col.a); \n \
                 }";
        GLProgram* pProgram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, pszFragSource);
        sp->setGLProgram(pProgram);
}


void SpriteUtils::removeGray(Node* sp)
{
        GLProgram* pProgram = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP);
        sp->setGLProgram(pProgram);
        CHECK_GL_ERROR_DEBUG();
}

void SpriteUtils::addBlack(Node *node) {

    GLchar* pszFragSource =
            "#ifdef GL_ES \n \
             precision mediump float; \n \
             #endif \n \
             varying vec2 v_texCoord; \n \
             varying vec4 v_fragmentColor; \n \
             void main(void) \n \
             { \n \
             // Convert to greyscale using NTSC weightings \n \
             vec4 col = v_fragmentColor*texture2D(CC_Texture0, v_texCoord); \n \
             float black = dot(col.rgb, vec3(0.000, 0.000, 0.000)); \n \
             gl_FragColor = vec4(black, black, black, col.a); \n \
             }";
    GLProgram* pProgram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, pszFragSource);
    node->setGLProgram(pProgram);
}

void SpriteUtils::setSwallowTouches(cocos2d::Node *layer, bool isRemove) {

    static cocos2d::EventListenerTouchOneByOne *touchListener = EventListenerTouchOneByOne::create();
    static int count =0;
    if(count==0) {
        touchListener->retain();
        touchListener->setSwallowTouches(true);
        touchListener->onTouchBegan = [](Touch *touch, Event *event) -> bool {
            return true;
        };
    }
    if(!layer) return;
    if(layer->getChildrenCount()<=0) return;

    auto itemes = layer->getChildren();
    int index = 0;
    for(auto it = itemes.begin();it!=itemes.end();++it)
    {
        auto eventDispatcher = Director::getInstance()->getEventDispatcher();
        Node *item = *it;
        SpriteUtils::setSwallowTouches(item, isRemove);

        if(isRemove) {
            EventListenerTouchOneByOne *listener = (index == 0) ? touchListener : touchListener->clone();
            eventDispatcher->addEventListenerWithSceneGraphPriority(listener, item);
            eventDispatcher->addEventListenerWithFixedPriority(listener, -128);
        }else{
            eventDispatcher->removeEventListener(touchListener);
        }
    }

    count++;

}
