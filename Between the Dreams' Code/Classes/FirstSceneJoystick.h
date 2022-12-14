// 第一关控制人物摇杆

#ifndef __FIRSTJOYSTICK_H__
#define __FIESTJOYSTICK_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;

#include "config_set.h"

enum Joystick_dir
{
	_LEFT,
	_RIGHT,
	_STOP
};

class FirstSceneJoystick : public Layer
{
public:
	FirstSceneJoystick();
	~FirstSceneJoystick();

	// 初始化 aPoint是摇杆中心 aRadius是摇杆半径 aJsSprite是摇杆控制点 aJsBg是摇杆背景
	static FirstSceneJoystick* create(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);

	// 获取摇杆方向
	Joystick_dir getDirection();

private:
	float getVelocity();   // 摇杆力度
	void update(float dt); 
	virtual bool init(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

private:
	Vec2 m_centerPoint;    // 摇杆中心
	Vec2 m_currentPoint;   // 摇杆当前位置
	float m_radius;        // 摇杆半径
	Sprite* m_jsSprite;
};

#endif
