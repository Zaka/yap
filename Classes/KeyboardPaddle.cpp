#include "KeyboardPaddle.h"
#include "Ball.h"

USING_NS_CC;

KeyboardPaddle::KeyboardPaddle()
        :_offset(0.0) {
        auto keyboardListener = EventListenerKeyboard::create();
        keyboardListener->onKeyPressed = CC_CALLBACK_2(KeyboardPaddle::onKeyPressed, this);
        keyboardListener->onKeyReleased = CC_CALLBACK_2(KeyboardPaddle::onKeyReleased, this);
    
        _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

        schedule( schedule_selector(KeyboardPaddle::move));
}

KeyboardPaddle* KeyboardPaddle::createWithTexture(Texture2D* texture) {
        KeyboardPaddle* pPaddle = new KeyboardPaddle();
        pPaddle->initWithTexture(texture);
        pPaddle->autorelease();

        return pPaddle;
}

void KeyboardPaddle::move(float delta) {
        // TODO: Change to setPositionY()
        setPosition(40, getPosition().y + _offset);
}

void KeyboardPaddle::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
        Paddle::onKeyPressed(keyCode, event);
    
        if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
                _offset = 10.0;
                // setPosition(40, getPosition().y + offset);
        } else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
                _offset = -10.0;
                // setPosition(40, getPosition().y - offset);
        }

        log("Key with keycode %d pressed", keyCode);
}

void KeyboardPaddle::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
        if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW
            || keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
                _offset = 0.0;
        }
        log("Key with keycode %d released", keyCode);
}

bool KeyboardPaddle::collideWithBall(Ball* ball) {
        auto paddleBBox = getBoundingBox();
        auto ballBBox = ball->getBoundingBox();

        float bLeft = ballBBox.getMinX();
        float bHigh = ballBBox.getMaxY();
        float bLow = ballBBox.getMinY();

        float pRight = paddleBBox.getMaxX();
        float pHigh = paddleBBox.getMaxY();
        float pLow = paddleBBox.getMinY();

        if (bLeft <= pRight) {
                if (bHigh <= pHigh
                    && bHigh >= pLow) {
                        return true;
                } else if (bLow <= pHigh
                           && bLow >= pLow) {
                        return true;
                }
        }

        return false;
}

int const KeyboardPaddle::sign() const {
        return 1;
}
