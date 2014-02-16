#ifndef BALL_H
#define BALL_H

#include "cocos2d.h"

class Paddle;

class Ball : public cocos2d::Sprite
{
    cocos2d::EventListenerMouse* _mouseListener;
    cocos2d::Point _velocity;
public:
    Ball();
    virtual ~Ball();

    void move(float delta);
    
    static Ball* createWithTexture(cocos2d::Texture2D* aTexture);
    void collideWithPaddle(Paddle* paddle);
private:
    cocos2d::Point const getVelocity();
    void setVelocity(cocos2d::Point velocity);
    float radius();
};

#endif
