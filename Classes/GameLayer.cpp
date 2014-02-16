#include <iostream>

#include "GameLayer.h"
#include "Ball.h"
#include "Paddle.h"

USING_NS_CC;

GameLayer::GameLayer()
    :_ball(NULL){
    auto ballTexture = Director::getInstance()->getTextureCache()->addImage("ball.png");
    auto paddleTexture = Director::getInstance()->getTextureCache()->addImage("paddle.png");
    
    _ball = Ball::createWithTexture(ballTexture);
    _paddle = Paddle::createWithTexture(paddleTexture);
    
    _ball->setPosition(300,300);
    //_paddle->setPosition(200,200);

    addChild(_ball);
    addChild(_paddle);
        
    schedule( schedule_selector(GameLayer::doStep));
}

void GameLayer::doStep(float delta) {
    _ball->move(delta);

    // for (auto& paddle : _paddles)
    //     {
    //         _ball->collideWithPaddle( paddle );
    //     }

    // if (_ball->getPosition().y > VisibleRect::top().y - kStatusBarHeight + _ball->radius())
    //     resetAndScoreBallForPlayer( kLowPlayer );
    // else if (_ball->getPosition().y < VisibleRect::bottom().y-_ball->radius())
    //     resetAndScoreBallForPlayer( kHighPlayer );

}
