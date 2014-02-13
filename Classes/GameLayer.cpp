#include <iostream>

#include "GameLayer.h"
#include "Ball.h"

USING_NS_CC;

GameLayer::GameLayer()
    :_ball(NULL){
    auto ballTexture = Director::getInstance()->getTextureCache()->addImage("ball.png");
    _ball = Ball::createWithTexture(ballTexture);
    _ball->setPosition(300,300);

    addChild(_ball);
    
    schedule( schedule_selector(GameLayer::doStep) );
}

void GameLayer::doStep(float delta) {
    std::cout << "GameLayer: doing step" << std::endl
              << "delta: " << delta << std::endl;
        
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
