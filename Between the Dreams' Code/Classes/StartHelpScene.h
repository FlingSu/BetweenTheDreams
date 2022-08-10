//帮助界面
#pragma once

#ifndef _STARTHELPSCENE_H
#define _STARTHELPSCENE_H

#include "cocos2d.h"
using namespace cocos2d;    //使用cocos2d命名空间

class StartHelpScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void BackCallback(Ref* pSender);

    CREATE_FUNC(StartHelpScene);

};

#endif // !_STARTHELPSCENE_H
