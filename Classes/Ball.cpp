#include <iostream>

#include "Ball.h"
#include "VisibleRect.h"
#include "AppDelegate.h"
#include "Paddle.h"

USING_NS_CC;

Ball::Ball() {
    setAnchorPoint(Point::ZERO);
}

Ball::~Ball() {}

void Ball::move(float delta) {
    this->setPosition(getPosition() + getVelocity() * delta);

    if (getPosition().x > VisibleRect::right().x - radius()) {
        setPosition(Point(VisibleRect::right().x - radius(),
                          getPosition().y) );
        _velocity.x *= -1;
    } else if (getPosition().x < VisibleRect::left().x + radius()) {
        setPosition(Point(VisibleRect::left().x + radius(),
                          getPosition().y) );
        _velocity.x *= -1;
    }

    if (getPosition().y > VisibleRect::top().y - radius()) {
        setPosition(Point(getPosition().x,
                          VisibleRect::top().y - radius()));
        _velocity.y *= -1;
    } else if (getPosition().y < VisibleRect::bottom().y + radius()) {
        setPosition(Point(getPosition().x,
                          VisibleRect::bottom().y + radius()));
        _velocity.y *= -1;
    }
}

Ball* Ball::createWithTexture(Texture2D* aTexture)
{
    Ball* pBall = new Ball();
    pBall->initWithTexture(aTexture);
    pBall->autorelease();

    return pBall;
}

Point const Ball::getVelocity() {
    return _velocity;
}

void Ball::setVelocity(Point velocity) {
    _velocity = velocity;
}

float Ball::radius()
{
    return getTexture()->getContentSize().width / 2;
}

std::string toString(Point point) {
    std::stringstream ss;

    ss << "(x: " << point.x << ", y: " << point.y << ")";

    return ss.str();
}

std::string toString(Rect rect) {
    std::stringstream ss;

    ss << "Lower Left Corner: "
       << toString(Point(rect.getMinX(), rect.getMinY())) << " "
       << "Upper Right Corner: "
       << toString(Point(rect.getMaxX(), rect.getMaxY()));

    
    return ss.str();
}

void Ball::collideWithPaddle(Paddle* paddle) {
    if (paddle->collideWithBall(this)) {
        _velocity.x = paddle->sign() * std::abs(_velocity.x);
    }
}
