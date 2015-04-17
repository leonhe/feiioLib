//
// Created by Yuanfei He on 15/4/9.
//

#include "SpriteUtils.h"
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
                 float grey = dot(col.rgb, vec3(0.299, 0.587, 0.114)); \n \
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