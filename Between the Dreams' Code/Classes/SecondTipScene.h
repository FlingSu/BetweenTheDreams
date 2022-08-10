//第二张小纸条界面
#pragma once
#ifndef _SECONDTIPSCENE_H_
#define _SECONDTIPSCENE_H_

#include"ThirdPassScene.h"
#include"config_set.h"
#include "cocos2d.h"
using namespace cocos2d;    //使用cocos2d命名空间

class SecondTipScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void NextCallback(Ref* pSender);
    CREATE_FUNC(SecondTipScene);
};

#endif // !_SECONDTIPSCENE_H_
