#include <iostream>
#include "GameScene.h"

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

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
  std::cout << "Initing GameScene..." << std::endl;
  
  //////////////////////////////
  // 1. super init first
  if ( !Layer::init() )
    {
      return false;
    }

  _ballSprite = Sprite::create("ball.png");
  _ballSprite->setPosition(400, 400);
  this->addChild(_ballSprite, 0);

  _mouseListener = EventListenerMouse::create();
  _mouseListener->onMouseMove = CC_CALLBACK_1(GameScene::onMouseMove, this);

  _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
   
  return true;
}

void GameScene::onMouseMove(Event *event)
{
  EventMouse *e = (EventMouse*)event;

  std::cout << "x: " << e->getCursorX()
            << " y: " << e->getCursorY()
            << std::endl;
}
