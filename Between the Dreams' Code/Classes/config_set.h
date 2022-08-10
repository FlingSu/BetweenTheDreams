//全局变量在这里设置
#pragma once

#ifndef __CONFIG_SET_H__
#define __CONFIG_SET_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace cocos2d;
using namespace cocostudio;
using namespace cocos2d::ui;
using namespace std;

static bool testtheTime;

// shan：FirstScene player Swim
static string PLAYER_IMG_SWIM_PATH[4] =
{
	"FirstPassScene/swim/swim1.png",
	"FirstPassScene/swim/swim2.png",
	"FirstPassScene/swim/swim3.png",
	"FirstPassScene/swim/swim4.png"
};

// shan：FirstScene player Stop
static string PLAYER_IMG_STOP_PATH[6] =
{
	"FirstPassScene/stop/stop1.png",
	"FirstPassScene/stop/stop2.png",
	"FirstPassScene/stop/stop3.png",
	"FirstPassScene/stop/stop4.png",
	"FirstPassScene/stop/stop3.png",
	"FirstPassScene/stop/stop2.png"
};

//shan:
static const int FIRSTSCENE_PLAYER_TAG = 110;  // player tag
static const int FIRSTSCENE_MAP_TAG = 111;     // map tag

//su:player的运动方向
enum Dir
{
	STOP,
	UP,
	DOWN
};

//su:通关结果的tips图片
static string GAME_OVER_TIPS = "tipsImg/gameover.png";  // game failed tips words
static string GAME_SUCCESS = "tipsImg/success.png";      // game success tips words
static string GAME_PASSALL = "tipsImg/passAll.png";      // game success tips words
static string GAME_OVER_TIPS2 = "tipsImg/gameover2.png";  // game failed tips words
static string GAME_OVER_TIPS3 = "tipsImg/gameover3.png";  // game failed tips words

//shan:重新开始的图片
static string REPLAY = "tipsImg/replay.png";
static string NEXT = "tipsImg/next.png";
static string END = "tipsImg/end.png";
static string TIP = "tipsImg/tip.png";

//su:
static string REPLAY2 = "tipsImg/replay2.png";
static string NEXT2 = "tipsImg/next2.png";
static string END2 = "tipsImg/end2.png";
static string TIP2 = "tipsImg/tip2.png";


#endif