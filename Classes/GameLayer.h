#ifndef GAMELAYER_H
#define GAMELAYER_H

#include "cocos2d.h"

class Ball;
class Paddle;

class GameLayer : public cocos2d::Layer {
    static const float PADDLE_01_X_POS;
    static const float PADDLE_02_X_POS;
    Ball* _ball;
    Paddle* _paddle_01;
    Paddle* _paddle_02;
public:
    GameLayer();
    void doStep(float delta);
};


#endif //GAMELAYER_H
