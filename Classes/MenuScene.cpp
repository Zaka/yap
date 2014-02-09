#include <iostream>
#include "MenuScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
  // 'scene' is an autorelease object
  auto scene = Scene::create();
    
  // 'layer' is an autorelease object
  auto layer = MenuScene::create();

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
  std::cout << "Initing MenuScene..." << std::endl;
  
  if ( !Layer::init() ) {
    return false;
  }
    
  auto playItem = MenuItemImage::create("btn-play-normal.png",
                                        "btn-play-selected.png",
                                        CC_CALLBACK_1(MenuScene::onPlay, this));
    
  // playItem->setPosition(Point(origin.x + visibleSize.width - playItem->getContentSize().width/2 ,
  //                             origin.y + playItem->getContentSize().height/2));

  playItem->setPosition(Point(200,400));
      
  // create menu, it's an autorelease object
  auto playMenu = Menu::create(playItem, NULL);
  playMenu->setPosition(Point::ZERO);
  this->addChild(playMenu, 1);

  auto exitItem = MenuItemImage::create("CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(MenuScene::onExit, this));
    
  // exitItem->setPosition(Point(origin.x + visibleSize.width - exitItem->getContentSize().width/2 ,
  //                             origin.y + exitItem->getContentSize().height/2));

  exitItem->setPosition(Point(200, 200));
   
  // create menu, it's an autorelease object
  auto exitMenu = Menu::create(exitItem, NULL);
  exitMenu->setPosition(Point::ZERO);
  this->addChild(exitMenu, 1);
    
  return true;
}

void MenuScene::onExit(Object* pSender)
{
  Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}

void MenuScene::onPlay(Object* pSender)
{
  std::cout << "Playing..." << std::endl;

  auto scene = GameScene::createScene();
  
  Director::getInstance()->replaceScene(scene);
}
