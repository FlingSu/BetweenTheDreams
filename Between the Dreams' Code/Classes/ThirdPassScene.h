//第三关场景
#ifndef _THIRDPASSSCENE_H_
#define _THIRDPASSSCENE_H_

#include"config_set.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
using namespace ui;
using namespace cocos2d;    //使用cocos2d命名空间
using namespace cocostudio;

#include "GameTimer.h"

// animation img path
static string ANIMATION_IMG_PATH[4] =
{
    "thirdPassresource/amo1.png",
    "thirdPassresource/amo2.png",
    "thirdPassresource/amo3.png",
    "thirdPassresource/amo4.png"
};

// animation pass img path
static string ANIMATIONPASS_IMG_PATH[2] =
{
    "thirdPassresource/amo7.png",
    "thirdPassresource/amo8.png"
};

// animation error img path
static string ANIMATIONERROR_IMG_PATH[2] =
{
    "thirdPassresource/amo5.png",
    "thirdPassresource/amo6.png"
};

static int ANIMATION_WIDTH = 1024;		// player img width
static int ANIMATION_HEIGHT = 768;	    // player img height

static const int ANIMATION_TAG = 51;  
static const int ANIMATIONPASS_TAG = 52;
static const int ANIMATIONERROR_TAG = 53;

class ThirdPassScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // 游戏逻辑
    void update(float t);
    void addAnimation(Vec2 pos);
    void addAnimationPass(Vec2 pos);
    void addAnimationError(Vec2 pos);
    void onClick_1a(Ref* sender);
    void onClick_1b(Ref* sender);
    void onClick_1c(Ref* sender);
    void onClick_1d(Ref* sender);
    void onClick_2a(Ref* sender);
    void onClick_2b(Ref* sender);
    void onClick_2c(Ref* sender);
    void onClick_2d(Ref* sender);
    CREATE_FUNC(ThirdPassScene);

    void gameOver();
    void gameSuccess();
    //重新开始游戏
    void replayCallback(Ref* pSender);
    //结束游戏
    void endCallback(Ref* pSender);

    GameTimer* m_timer;
};


#endif // _THIRDPASSSCENE_H_