//第一关场景
#pragma once
#ifndef __FIRSTPASS_SCENE_H__
#define __FIRSTPASS_SCENE_H__

#include"config_set.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "FirstSceneJoystick.h"

USING_NS_CC;

using namespace cocos2d::ui;

class FirstPassScene : public cocos2d::Layer
{
public:

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(FirstPassScene);

	// 显示人物
	void addPlayer(Vec2 pos);

	// 游戏逻辑
	void update(float t);
	void replayCallback(Ref* pSender);
	void nextCallback(Ref* pSender);
	void endCallback(Ref* pSender);
	void tipsCallback(Ref* pSender);

	int mapType;	//门出现在 0 左 1 右
	bool m_gameOver; // 游戏是否结束
	Joystick_dir m_swimDir;   // 表示精灵的方向 0 left 1 right
	int m_swimLeftSpeed_1; // 逆流速度
	int m_swimLeftSpeed_2; // 逆流速度
	int m_swimRightSpeed_1;	//顺流速度
	int m_swimRightSpeed_2;	//顺流速度
	FirstSceneJoystick* m_joystick;   // 摇杆
	Sprite* paper;	//小纸条
	bool getPaper;	//有没有拿到小纸条
	Sprite* water1;	//流水
	Sprite* water2;
	Sprite* strengthBar0;	//体力条
	Sprite* strengthBar1;
	Sprite* strengthBar2;
	Sprite* strengthBar3;
	Sprite* strengthBar4;
	Sprite* strengthBar5;
	Sprite* strengthBar6;
	Sprite* strengthBar7;
	Sprite* strengthBar8;
	Sprite* strengthBar9;
	Sprite* strengthBar10;
	Sprite* strengthBar11;
	Sprite* strengthBar12;
	Sprite* strengthBar13;
	int strength;	//体力值
	int PLAYER_WIDTH;		// player img width
	int PLAYER_HEIGHT;	    // player img height
	int up;
};

#endif // __FIRSTPASS_SCENE_H__

