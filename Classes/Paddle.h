#ifndef PADDLE_H
#define PADDLE_H

#include "cocos2d.h"

class Ball;

class Paddle : public cocos2d::Sprite {
protected:
    std::string toString(cocos2d::Point point);
    
public:
    Paddle();
    ~Paddle();
    virtual bool collideWithBall(Ball *ball) = 0;
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    virtual int const sign() const = 0;
};

#endif //PADDLE_H
