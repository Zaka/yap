#include "iostream"
#include "Paddle.h"
#include "VisibleRect.h"

USING_NS_CC;

Paddle::Paddle() {
    setAnchorPoint(Point::ZERO);
}

Paddle::~Paddle() {
}

std::string Paddle::toString(Point point) {
    std::stringstream ss;
    ss << "(" << point.x << ", "  << point.y << ")";
    
    return ss.str();
}

void Paddle::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_P) {
            // auto paddleRect = getRect();
    }
}
