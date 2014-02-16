#ifndef PADDLE_H
#define PADDLE_H

#include "cocos2d.h"

class Paddle : public cocos2d::Sprite {
    cocos2d::EventListenerMouse *_mouseListener;
public:
    static const float POS_Y;
    
    Paddle();
    ~Paddle();
    cocos2d::Rect getRect();
    void onMouseMove(cocos2d::Event *event);
    static Paddle* createWithTexture(cocos2d::Texture2D* texture);
};

#endif //PADDLE_H
