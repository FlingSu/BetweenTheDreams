// ��һ�ؿ�������ҡ��

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

	// ��ʼ�� aPoint��ҡ������ aRadius��ҡ�˰뾶 aJsSprite��ҡ�˿��Ƶ� aJsBg��ҡ�˱���
	static FirstSceneJoystick* create(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);

	// ��ȡҡ�˷���
	Joystick_dir getDirection();

private:
	float getVelocity();   // ҡ������
	void update(float dt); 
	virtual bool init(Vec2 aPoint ,float aRadius ,char* aJsSprite,char* aJsBg);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);

private:
	Vec2 m_centerPoint;    // ҡ������
	Vec2 m_currentPoint;   // ҡ�˵�ǰλ��
	float m_radius;        // ҡ�˰뾶
	Sprite* m_jsSprite;
};

#endif
