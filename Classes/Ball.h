#ifndef BALL_H
#define BALL_H

#include "cocos2d.h"

class Ball : public cocos2d::Sprite
{
    cocos2d::EventListenerMouse* _mouseListener;
public:
    Ball();
    virtual ~Ball();

    static Ball* createWithTexture(cocos2d::Texture2D* aTexture);
    void onMouseMove(cocos2d::Event *event);
};

#endif
