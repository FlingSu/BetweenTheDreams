//��һ�س���
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

	// ��ʾ����
	void addPlayer(Vec2 pos);

	// ��Ϸ�߼�
	void update(float t);
	void replayCallback(Ref* pSender);
	void nextCallback(Ref* pSender);
	void endCallback(Ref* pSender);
	void tipsCallback(Ref* pSender);

	int mapType;	//�ų����� 0 �� 1 ��
	bool m_gameOver; // ��Ϸ�Ƿ����
	Joystick_dir m_swimDir;   // ��ʾ����ķ��� 0 left 1 right
	int m_swimLeftSpeed_1; // �����ٶ�
	int m_swimLeftSpeed_2; // �����ٶ�
	int m_swimRightSpeed_1;	//˳���ٶ�
	int m_swimRightSpeed_2;	//˳���ٶ�
	FirstSceneJoystick* m_joystick;   // ҡ��
	Sprite* paper;	//Сֽ��
	bool getPaper;	//��û���õ�Сֽ��
	Sprite* water1;	//��ˮ
	Sprite* water2;
	Sprite* strengthBar0;	//������
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
	int strength;	//����ֵ
	int PLAYER_WIDTH;		// player img width
	int PLAYER_HEIGHT;	    // player img height
	int up;
};

#endif // __FIRSTPASS_SCENE_H__

