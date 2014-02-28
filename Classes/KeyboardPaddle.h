#ifndef KEYBOARDPADDLE_H
#define KEYBOARDPADDLE_H

#include "Paddle.h"

class Ball;

class KeyboardPaddle : public Paddle {
    float _offset;
    void move(float delta);
public:
    KeyboardPaddle();
    
    static KeyboardPaddle* createWithTexture(cocos2d::Texture2D* texture);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode,
                      cocos2d::Event *event);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode,
                      cocos2d::Event *event);
    virtual bool collideWithBall(Ball *ball);
    int const sign() const;
};


#endif
