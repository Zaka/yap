#include <iostream>
#include "GameScene.h"
#include "GameLayer.h"
#include "Ball.h"

USING_NS_CC;

GameScene::GameScene() {
    auto gameLayer = new GameLayer();
    addChild(gameLayer);
    gameLayer->release();
}
