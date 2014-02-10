#include <iostream>
#include "Ball.h"

USING_NS_CC;

Ball::Ball() {
    std::cout << "Ball::Constructor" << std::endl;
    _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = CC_CALLBACK_1(Ball::onMouseMove, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
}

Ball::~Ball() {
    _eventDispatcher->removeEventListener(_mouseListener);
}

void Ball::onMouseMove(Event *event) {
    EventMouse *e = (EventMouse*)event;

    std::cout << "Ball x: " << e->getCursorX()
              << " y: " << e->getCursorY()
              << std::endl;

    setPosition(Point(e->getCursorX(), e->getCursorY()));
}

Ball* Ball::createWithTexture(Texture2D* aTexture)
{
    Ball* pBall = new Ball();
    pBall->initWithTexture(aTexture);
    pBall->autorelease();

    return pBall;
}


