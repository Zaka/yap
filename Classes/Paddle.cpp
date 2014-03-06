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

Rect Paddle::getBoundingBox() const 
{
        Rect result = Sprite::getBoundingBox();

        // This offset improves the paddle collision feeling
        // It's the size of the ball
        auto offset = 16.0f; 
            
        result.origin.y += offset/2;
        result.size.height -= offset;

        return result;
}
