//��һ��Сֽ������
#pragma once
#ifndef __FIRST_TIP_SCENE_H__
#define __FIRST_TIP_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;    //ʹ��cocos2d�����ռ�

class FirstTipScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void NextCallback(Ref* pSender);
    CREATE_FUNC(FirstTipScene);

};

#endif //  __FIRST_TIP_SCENE_H__
