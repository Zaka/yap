#include <iostream>

#include "Ball.h"
#include "VisibleRect.h"

USING_NS_CC;

Ball::Ball()
    :_velocity(Point(100,100)){
    std::cout << "Ball::Constructor" << std::endl;
}

Ball::~Ball() {}

std::string toString(Point point) {
    std::stringstream ss;
    ss << point.x;
    ss << point.y;

    return ss.str();
}

void Ball::move(float delta) {
    std::cout << "Ball: moving..." << std::endl;

    std::cout << "Ball: previous position: " << toString(getPosition()) << std::endl;
        
    this->setPosition(getPosition() + getVelocity() * delta);

    std::cout << "Ball: after setting position: " << toString(getPosition()) << std::endl;
    
    if (getPosition().x > VisibleRect::right().x - radius()) {
        setPosition( Point( VisibleRect::right().x - radius(), getPosition().y) );
        _velocity.x *= -1;
    } else if (getPosition().x < VisibleRect::left().x + radius()) {
        setPosition( Point(VisibleRect::left().x + radius(), getPosition().y) );
        _velocity.x *= -1;
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
