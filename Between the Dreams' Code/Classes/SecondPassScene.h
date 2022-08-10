//�ڶ��س���
#ifndef _SECONDPASSSCENE_H_
#define _SECONDPASSSCENE_H_

#include"config_set.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d::ui;

#include "SecondTipScene.h"

#include "ThirdPassScene.h"

static string MAP_TMX_FILE_PATH = "secondPassResource/runmap.tmx";
static string MAP_BG_LAYER_NAME = "mainLayer";  // map background layer name
static int PLAYER_JUMP_SPEED = 30;  // player jump speed
static const int PLAYER_TAG = 110;  // player tag
static const int MONSTER_TAG = 113;

static const int MAP_TAG = 111;     // map tag

static int PLAYER_WIDTH = 120;		// player img width
static int PLAYER_HEIGHT = 120;	    // player img height

static int MONSTER_WIDTH = 140;
static int MONSTER_HEIGHT = 140;

// player img path
static string PLAYER_IMG_PATH[3] = 
{
	//"secondPassResource/player1.png",
	"secondPassResource/player2.png",
	"secondPassResource/player3.png",
	"secondPassResource/player4.png"
};

static string MONSTER_IMG_PATH[4] =
{
	"secondPassResource/monster/monster1.png",
	"secondPassResource/monster/monster2.png",
	"secondPassResource/monster/monster3.png",
	"secondPassResource/monster/monster4.png"
};

std::string GBKToUTF8(const std::string& strGBK);

class SecondPass :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SecondPass);

	// ���ص�ͼ
	void loadMap(std::string mapPath);

	// ��ʾ����
	void addPlayer(Vec2 pos);
	//��ʾ����
	void addMonster(Vec2 pos);

	// ��Ӵ�������
	void addTouchListener();
	bool onTouchBegan(Touch* touch, Event* unused_event);

	//���¿�ʼ��Ϸ
	void replayCallback(Ref* pSender);
	void nextCallback(Ref* pSender);
	void endCallback(Ref* pSender);
	void tipsCallback(Ref* pSender);

	// ��Ϸ�߼�
	void update(float t);

	void gameOver();
	void success();

	bool m_gameOver; // ��Ϸ�Ƿ����
	Dir m_jumpDir;   // ��ʾ����ķ��� 1��up 2 down
	int m_jumpSpeed; // ��Ծ�ٶ�
	bool m_isJump;   // ��ʾ�Ƿ�������Ծ�������Ծ��������Ļ�Ĵ���
};

#endif