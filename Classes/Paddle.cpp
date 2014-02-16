#include "iostream"
#include "Paddle.h"
#include "VisibleRect.h"

USING_NS_CC;

const float Paddle::POS_Y = 910;

Paddle::Paddle() {
    _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = CC_CALLBACK_1(Paddle::onMouseMove, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener,
                                                             this);
}

Paddle::~Paddle() {
    _eventDispatcher->removeEventListener(_mouseListener);    
}

std::string toString(Point point) {
    std::stringstream ss;
    ss << "(" << point.x << ", "  << point.y << ")";
    
    return ss.str();
}

void Paddle::onMouseMove(Event *event) {
    EventMouse *e = (EventMouse*)event;
    this->setPosition(Point(Paddle::POS_Y, e->getCursorY()));

    std::cout << "Paddle pos: " << toString(getPosition()) << std::endl;
}

Paddle* Paddle::createWithTexture(Texture2D* texture) {
    Paddle* pPaddle = new Paddle();
    pPaddle->initWithTexture(texture);
    pPaddle->autorelease();

    pPaddle->setPosition(Paddle::POS_Y, VisibleRect::center().y);
    
    return pPaddle;
}

Rect Paddle::getRect()
{
    auto s = getTexture()->getContentSize();
    return Rect(-s.width / 2, -s.height / 2, s.width, s.height);
}
