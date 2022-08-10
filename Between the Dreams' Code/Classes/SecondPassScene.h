//第二关场景
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

	// 加载地图
	void loadMap(std::string mapPath);

	// 显示人物
	void addPlayer(Vec2 pos);
	//显示怪物
	void addMonster(Vec2 pos);

	// 添加触屏侦听
	void addTouchListener();
	bool onTouchBegan(Touch* touch, Event* unused_event);

	//重新开始游戏
	void replayCallback(Ref* pSender);
	void nextCallback(Ref* pSender);
	void endCallback(Ref* pSender);
	void tipsCallback(Ref* pSender);

	// 游戏逻辑
	void update(float t);

	void gameOver();
	void success();

	bool m_gameOver; // 游戏是否结束
	Dir m_jumpDir;   // 表示精灵的方向 1，up 2 down
	int m_jumpSpeed; // 跳跃速度
	bool m_isJump;   // 表示是否精灵在跳跃，如果跳跃不处理屏幕的触摸
};

#endif