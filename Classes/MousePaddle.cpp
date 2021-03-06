#include <iostream>

#include "MousePaddle.h"
#include "Ball.h"

USING_NS_CC;

MousePaddle::MousePaddle() {
    std::cout << "MousePaddle: Building" << std::endl;
    
    _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = CC_CALLBACK_1(MousePaddle::onMouseMove,
                                                this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                             this);
}

MousePaddle* MousePaddle::createWithTexture(Texture2D* texture) {
    MousePaddle* pPaddle = new MousePaddle();
    pPaddle->initWithTexture(texture);
    pPaddle->autorelease();

    return pPaddle;
}

MousePaddle::~MousePaddle() {
    _eventDispatcher->removeEventListener(_mouseListener);    
}

void MousePaddle::onMouseMove(Event *event) {
    EventMouse *e = (EventMouse*)event;
    this->setPosition(Point(910, e->getCursorY()));

    // std::cout << "Paddle pos: " << toString(getPosition()) << std::endl;
}

std::string MousePaddle::toString(Point point) {
    std::stringstream ss;

    ss << "(x: " << point.x << ", y: " << point.y << ")";

    return ss.str();
}

std::string MousePaddle::toString(Rect rect) {
    std::stringstream ss;

    ss << "Lower Left Corner: "
       << toString(Point(rect.getMinX(), rect.getMinY())) << " "
       << "Upper Right Corner: "
       << toString(Point(rect.getMaxX(), rect.getMaxY()));
    
    return ss.str();
}

bool MousePaddle::collideWithBall(Ball *ball) {
    auto paddleBBox = getBoundingBox();
    auto ballBBox = ball->getBoundingBox();
        
    float bRight = ballBBox.getMaxX();
    float bHigh = ballBBox.getMaxY();
    float bLow = ballBBox.getMinY();

    float pLeft = paddleBBox.getMinX();
    float pHigh = paddleBBox.getMaxY();
    float pLowY = paddleBBox.getMinY();
    
    if (bRight >= pLeft) {
        if (bHigh <= pHigh
            && bHigh >= pLowY) {
            return true;
        } else if (bLow <= pHigh
                   && bLow >= pLowY) {
            return true;
        }
    }
    
    return false;
}

int const MousePaddle::sign() const {
    return -1;
}
