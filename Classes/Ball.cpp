#include <iostream>

#include "Ball.h"
#include "VisibleRect.h"
#include "AppDelegate.h"

USING_NS_CC;

Ball::Ball()
    :_velocity(Point(400,400)){
    std::cout << "Ball::Constructor" << std::endl;
}

Ball::~Ball() {}

void Ball::move(float delta) {
    this->setPosition(getPosition() + getVelocity() * delta);

    if (getPosition().x > VisibleRect::right().x - radius()) {
        setPosition( Point( VisibleRect::right().x - radius(), getPosition().y) );
        _velocity.x *= -1;
    } else if (getPosition().x < VisibleRect::left().x + radius()) {
        setPosition( Point(VisibleRect::left().x + radius(), getPosition().y) );
        _velocity.x *= -1;
    }

    if (getPosition().y > VisibleRect::top().y - radius()) {
        setPosition(Point(getPosition().x, VisibleRect::top().y - radius()));
        _velocity.y *= -1;
    } else if (getPosition().y < VisibleRect::bottom().y + radius()) {
        setPosition(Point(getPosition().x, VisibleRect::bottom().y + radius()));
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
