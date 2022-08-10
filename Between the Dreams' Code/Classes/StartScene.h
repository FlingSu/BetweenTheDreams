//开始菜单界面
//#pragma once
#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;    //使用cocos2d命名空间

class StartScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void endCallback(Ref* pSender);
    void startCallback(Ref* pSender);
    void helpCallback(Ref* pSender);
    CREATE_FUNC(StartScene);
private:
};

#endif // __START_SCENE_H__
