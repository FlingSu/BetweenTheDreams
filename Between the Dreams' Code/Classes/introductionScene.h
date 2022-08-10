#pragma once
#ifndef _INTRODUCTIONSCENE_H_
#define _INTRODUCTIONSCENE_H_

#include "cocos2d.h"
using namespace cocos2d;    //使用cocos2d命名空间

class introductionScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    bool onTouchBegan(Touch* touch, Event* unused_event);
    CREATE_FUNC(introductionScene);
};

#endif // !_INTRODUCTIONSCENE_H_
