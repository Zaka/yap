#ifndef GAMELAYER_H
#define GAMELAYER_H

#include "cocos2d.h"

class Ball;

class GameLayer : public cocos2d::Layer {
    Ball *_ball;
public:
    GameLayer();
    void doStep(float delta);
};


#endif //GAMELAYER_H
