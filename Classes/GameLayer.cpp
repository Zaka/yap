#include <iostream>

#include "GameLayer.h"
#include "Ball.h"
#include "MousePaddle.h"
#include "KeyboardPaddle.h"
#include "VisibleRect.h"

USING_NS_CC;

const float GameLayer::PADDLE_01_X_POS = 910;
const float GameLayer::PADDLE_02_X_POS = 10;

GameLayer::GameLayer()
    :_ball(NULL) {
    setAnchorPoint(Point::ZERO);
    setPosition(Point(0,0));
    
    auto ballTexture = Director::getInstance()->getTextureCache()->addImage("ball.png");
    auto paddleTexture = Director::getInstance()->getTextureCache()->addImage("paddle.png");
    
    _ball = Ball::createWithTexture(ballTexture);
    _paddle_01 = MousePaddle::createWithTexture(paddleTexture);
    _paddle_02 = KeyboardPaddle::createWithTexture(paddleTexture);

    _ball->setPosition(300,300);
    _paddle_01->setPosition(GameLayer::PADDLE_01_X_POS, 200);
    _paddle_02->setPosition(GameLayer::PADDLE_02_X_POS, 200);

    _ball->setVelocity(Point(100, 100));
    
    addChild(_ball);
    addChild(_paddle_01);
    addChild(_paddle_02);
        
    schedule( schedule_selector(GameLayer::doStep));
}

void GameLayer::doStep(float delta) {
    _ball->move(delta);

    _ball->collideWithPaddle(_paddle_01);
    _ball->collideWithPaddle(_paddle_02);

    //Increase velocity
    _ball->setVelocity(Point(1.0002 * _ball->getVelocity().x,
                             1.0002 * _ball->getVelocity().y));
        
    if (_ball->getPosition().x >= VisibleRect::right().x - _ball->radius()) {
        //Score for left player

        //Reset ball's' position
        _ball->setPosition(VisibleRect::right().x - 100, VisibleRect::center().y);
        _ball->setVelocity(Point(-100, -100));
    }

    if (_ball->getPosition().x <= VisibleRect::left().x + _ball->radius()) {
        //Score for right player

        //Reset ball's position
        _ball->setPosition(VisibleRect::left().x + 100, VisibleRect::center().y);
        _ball->setVelocity(Point(100, 100));
    }
}
