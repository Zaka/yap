#include <iostream>
#include "GameScene.h"
#include "Ball.h"

USING_NS_CC;

GameScene::~GameScene()
{
    _eventDispatcher->removeEventListener(_mouseListener);
}

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    auto ballTexture = Director::getInstance()->getTextureCache()->addImage("ball.png");
    
    auto ball = Ball::createWithTexture(ballTexture);

    scene->setPosition(Point::ZERO);
    layer->setPosition(Point::ZERO);
    ball->setPosition(300,300);
    
    layer->addChild(ball);
    
    // add layer as a child to scene
    scene->addChild(layer);

    // layer->release();
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init() {
    std::cout << "Initializing GameScene..." << std::endl;
  
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() ) {
        return false;
    }

    _mouseListener = EventListenerMouse::create();
    _mouseListener->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

    return true;
}

void GameScene::onMouseMove(Event *event)
{
    // EventMouse *e = (EventMouse*)event;

    // std::cout << "x: " << e->getCursorX()
    //           << " y: " << e->getCursorY()
    //           << std::endl;
}
