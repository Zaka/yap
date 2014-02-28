#ifndef MOUSEPADDLE_H
#define MOUSEPADDLE_H

#include "cocos2d.h"
#include "Paddle.h"

class MousePaddle : public Paddle {
    cocos2d::EventListenerMouse *_mouseListener;
    std::string toString(cocos2d::Point point);
    std::string toString(cocos2d::Rect rect);
public:
    MousePaddle();
    ~MousePaddle();
    void onMouseMove(cocos2d::Event *event);
    static MousePaddle* createWithTexture(cocos2d::Texture2D* texture);
    bool collideWithBall(Ball *ball);
    int const sign() const;
};


#endif
