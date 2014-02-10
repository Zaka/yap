#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
    cocos2d::EventListenerMouse* _mouseListener;
    cocos2d::Sprite * _ballSprite;
public:
    ~GameScene();
    static cocos2d::Scene* createScene();
    virtual bool init();
    void onMouseMove(cocos2d::Event *event);

    CREATE_FUNC(GameScene);
};

#endif //__GAMESCENE_H__
