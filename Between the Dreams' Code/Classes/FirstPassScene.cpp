//第一关场景
#include "AppDelegate.h"
#include "FirstPassScene.h"
#include "FirstTipScene.h"
#include "SecondPassScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace CocosDenshion;

Scene* FirstPassScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = FirstPassScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool FirstPassScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	m_swimDir = Joystick_dir::_STOP;
	m_swimLeftSpeed_1 = 5;
	m_swimRightSpeed_1 = 10;
	m_swimLeftSpeed_2 = 10;
	m_swimRightSpeed_2 = 5;
	m_gameOver = false;
	PLAYER_WIDTH = 2048;
	PLAYER_HEIGHT = 2048;
	getPaper = false;
	strength = 10500;

	mapType = rand() % 2;
	CCLOG("maptype %d", mapType);
	//mapType = 1;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto audioengine = SimpleAudioEngine::getInstance();
	audioengine->playBackgroundMusic("bgm/pass1bgm.mp3", true);

	// 加载地图
	if (mapType == 1)
	{
		auto map = TMXTiledMap::create("FirstPassScene/map/FirstPassSceneMap2.tmx");
		Size mapSize = map->getMapSize();
		Size tiledSize = map->getTileSize();
		map->setPosition(Vec2(-2400, 0));
		map->setTag(FIRSTSCENE_MAP_TAG);
		this->addChild(map, 2);
	}
	else
	{
		auto map = TMXTiledMap::create("FirstPassScene/map/FirstPassSceneMap.tmx");
		Size mapSize = map->getMapSize();
		Size tiledSize = map->getTileSize();
		map->setPosition(Vec2(-2400, 0));
		map->setTag(FIRSTSCENE_MAP_TAG);
		this->addChild(map, 2);
	}

	// 添加玩家
	addPlayer(Vec2(512, 192));

	// 摇杆
	m_joystick = FirstSceneJoystick::create(Vec2(100, 100), 50.0f, "FirstPassScene/ctrl/j-btn.png", "FirstPassScene/ctrl/j-bg.png");
	this->addChild(m_joystick, 30);

	//标题
	auto title = Sprite::create("tipsImg/FirstTitle.png");
	title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 150));
	this->addChild(title, 50);

	//小纸条
	paper = Sprite::create("FirstPassScene/ctrl/paper.png");
	paper->setTag(30);
	paper->setPosition(Vec2(174, 200));
	this->addChild(paper, 20);

	//流水
	water1 = Sprite::create("FirstPassScene/map/w1.png");
	water1->setTag(31);
	if (mapType == 1)
	{
		water1->setScaleX(-1);
		water1->setPosition(Vec2(512, 96));
	}
	water1->setPosition(Vec2(512, 96));
	this->addChild(water1, 25);
	water2 = Sprite::create("FirstPassScene/map/w2.png");
	water2->setTag(32);
	if (mapType == 1)
	{
		water2->setScaleX(-1);
		water2->setPosition(Vec2(1536, 96));
	}
	else
		water2->setPosition(Vec2(-512, 96));

	this->addChild(water2, 25);

	//体力条
	strengthBar0 = Sprite::create("FirstPassScene/ctrl/14.png");
	strengthBar0->setScale(0.3);
	strengthBar0->setPosition(Vec2(150, 550));
	this->addChild(strengthBar0, 48);
	strengthBar1 = Sprite::create("FirstPassScene/ctrl/1.png");
	strengthBar1->setScale(0.3);
	strengthBar1->setPosition(Vec2(150, 550));
	this->addChild(strengthBar1, 47);
	strengthBar2 = Sprite::create("FirstPassScene/ctrl/2.png");
	strengthBar2->setScale(0.3);
	strengthBar2->setPosition(Vec2(150, 550));
	this->addChild(strengthBar2, 46);
	strengthBar3 = Sprite::create("FirstPassScene/ctrl/3.png");
	strengthBar3->setScale(0.3);
	strengthBar3->setPosition(Vec2(150, 550));
	this->addChild(strengthBar3, 45);
	strengthBar4 = Sprite::create("FirstPassScene/ctrl/4.png");
	strengthBar4->setScale(0.3);
	strengthBar4->setPosition(Vec2(150, 550));
	this->addChild(strengthBar4, 44);
	strengthBar5 = Sprite::create("FirstPassScene/ctrl/5.png");
	strengthBar5->setScale(0.3);
	strengthBar5->setPosition(Vec2(150, 550));
	this->addChild(strengthBar5, 43);
	strengthBar6 = Sprite::create("FirstPassScene/ctrl/6.png");
	strengthBar6->setScale(0.3);
	strengthBar6->setPosition(Vec2(150, 550));
	this->addChild(strengthBar6, 42);
	strengthBar7 = Sprite::create("FirstPassScene/ctrl/7.png");
	strengthBar7->setScale(0.3);
	strengthBar7->setPosition(Vec2(150, 550));
	this->addChild(strengthBar7, 41);
	strengthBar8 = Sprite::create("FirstPassScene/ctrl/8.png");
	strengthBar8->setScale(0.3);
	strengthBar8->setPosition(Vec2(150, 550));
	this->addChild(strengthBar8, 40);
	strengthBar9 = Sprite::create("FirstPassScene/ctrl/9.png");
	strengthBar9->setScale(0.3);
	strengthBar9->setPosition(Vec2(150, 550));
	this->addChild(strengthBar9, 39);
	strengthBar10 = Sprite::create("FirstPassScene/ctrl/10.png");
	strengthBar10->setScale(0.3);
	strengthBar10->setPosition(Vec2(150, 550));
	this->addChild(strengthBar10, 38);
	strengthBar11 = Sprite::create("FirstPassScene/ctrl/11.png");
	strengthBar11->setScale(0.3);
	strengthBar11->setPosition(Vec2(150, 550));
	this->addChild(strengthBar11, 37);
	strengthBar12 = Sprite::create("FirstPassScene/ctrl/12.png");
	strengthBar12->setScale(0.3);
	strengthBar12->setPosition(Vec2(150, 550));
	this->addChild(strengthBar12, 36);
	strengthBar13 = Sprite::create("FirstPassScene/ctrl/13.png");
	strengthBar13->setScale(0.3);
	strengthBar13->setPosition(Vec2(150, 550));
	this->addChild(strengthBar13, 35);

	up = 0;

	// 游戏逻辑
	this->scheduleUpdate();

	// 添加触屏侦听
	//addTouchListener();

	return true;
}

void FirstPassScene::update(float t)
{
	auto player = this->getChildByTag(FIRSTSCENE_PLAYER_TAG);
	auto map = (TMXTiledMap*)getChildByTag(FIRSTSCENE_MAP_TAG);

	up++;
	//CCLOG("up = %d", up);
	// 玩家相对于屏幕的坐标
	float player_screen_x = player->getPositionX();
	float player_screen_y = player->getPositionY() - player->getContentSize().height / 2;

	// 地图相对于屏幕的x坐标
	float map_screen_x = abs(map->getPositionX());
	float map_screen_y = 0;

	// 玩家相对于地图的坐标
	float player_map_x = player_screen_x + map_screen_x;
	float player_map_y = player_screen_y + map_screen_y;

	// 滚动背景地图
	int mapWidth = map->getMapSize().width * map->getTileSize().width;
	int visibleWidth = Director::getInstance()->getWinSize().width;

	// 控制角色移动
	if (m_joystick->getDirection() == Joystick_dir::_RIGHT)
	{
		if (player->getScaleX() > 0)
			player->setScaleX(-0.1);
		if (mapType == 1)	//门在右
		{
			this->getChildByTag(FIRSTSCENE_MAP_TAG)->setPositionX(this->getChildByTag(FIRSTSCENE_MAP_TAG)->getPositionX() - m_swimRightSpeed_2);
			if (getPaper == false)
				paper->setPositionX(paper->getPositionX() - m_swimRightSpeed_2);
			strength -= 15;
			if (map->getPositionX() < -(mapWidth - visibleWidth))
			{
				map->setPositionX(-(mapWidth - visibleWidth));
				player->setPositionX(player->getPositionX() + m_swimRightSpeed_2);
			}
		}
		else
		{
			this->getChildByTag(FIRSTSCENE_MAP_TAG)->setPositionX(this->getChildByTag(FIRSTSCENE_MAP_TAG)->getPositionX() - m_swimRightSpeed_1);
			if (getPaper == false)
				paper->setPositionX(paper->getPositionX() - m_swimRightSpeed_1);
			strength -= 10;
			if (map->getPositionX() < -(mapWidth - visibleWidth))
			{
				map->setPositionX(-(mapWidth - visibleWidth));
				player->setPositionX(player->getPositionX() + m_swimRightSpeed_1);
				if (player->getPositionX() > 932)
					player->setPositionX(932);
			}
		}

	}
	else if (m_joystick->getDirection() == Joystick_dir::_LEFT)
	{
		if (player->getScaleX() < 0)
			player->setScaleX(0.1);
		if (mapType == 1)	//门在右
		{
			this->getChildByTag(FIRSTSCENE_MAP_TAG)->setPositionX(this->getChildByTag(FIRSTSCENE_MAP_TAG)->getPositionX() + m_swimLeftSpeed_2);
			if (getPaper == false)
				paper->setPositionX(paper->getPositionX() + m_swimLeftSpeed_2);
			strength -= 10;
			if (map->getPositionX() > 0)
			{
				map->setPositionX(0);
				player->setPositionX(player->getPositionX() - m_swimLeftSpeed_2);
				if (player->getPositionX() < 10)
					player->setPositionX(10);
			}
		}
		else
		{
			this->getChildByTag(FIRSTSCENE_MAP_TAG)->setPositionX(this->getChildByTag(FIRSTSCENE_MAP_TAG)->getPositionX() + m_swimLeftSpeed_1);
			if (getPaper == false)
				paper->setPositionX(paper->getPositionX() + m_swimLeftSpeed_1);
			strength -= 15;
			if (map->getPositionX() > 0)
			{
				map->setPositionX(0);
				player->setPositionX(player->getPositionX() - m_swimLeftSpeed_1);
			}
		}

	}
	else if (m_joystick->getDirection() == Joystick_dir::_STOP)
	{
		Vector<SpriteFrame* >frameVector1;
		for (int i = 0; i < 6; i++)
		{
			auto spriteFrame1 = SpriteFrame::create(PLAYER_IMG_STOP_PATH[i], Rect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
			frameVector1.pushBack(spriteFrame1);
		}
		auto animation1 = Animation::createWithSpriteFrames(frameVector1);
		animation1->setDelayPerUnit(0.07f);	//动画速度
		auto animate1 = Animate::create(animation1);
		player->setScale(0.1);
		player->runAction(animate1);
	}

	//进行碰撞检测
	if (getPaper == false)
	{
		if (player->getBoundingBox().intersectsRect(paper->getBoundingBox()))
		{
			this->removeChild(paper);
			getPaper = true;
		}
	}
	// 前景流水动画
	if (mapType == 1)
	{
		if (water1->getPositionX() <= -512)
		{
			water1->setPositionX(1524);
		}
		else
		{
			water1->setPositionX(water1->getPositionX() - 2);
		}
		if (water2->getPositionX() <= -512)
		{
			water2->setPositionX(1524);
		}
		else
		{
			water2->setPositionX(water2->getPositionX() - 2);
		}
	}
	else
	{
		if (water1->getPositionX() >= 1536)
		{
			water1->setPositionX(-500);
		}
		else
		{
			water1->setPositionX(water1->getPositionX() + 2);
		}
		if (water2->getPositionX() >= 1536)
		{
			water2->setPositionX(-500);
		}
		else
		{
			water2->setPositionX(water2->getPositionX() + 2);
		}
	}


	//体力条
	if (strength != 0)
	{
		if (strength <= 9630 && strength > 8760)
			this->removeChild(strengthBar1);
		else if (strength <= 8760 && strength > 7890)
			this->removeChild(strengthBar2);
		else if (strength <= 7890 && strength > 7020)
			this->removeChild(strengthBar3);
		else if (strength <= 7020 && strength > 6150)
			this->removeChild(strengthBar4);
		else if (strength <= 6150 && strength > 5280)
			this->removeChild(strengthBar5);
		else if (strength <= 5280 && strength > 4410)
			this->removeChild(strengthBar6);
		else if (strength <= 4410 && strength > 3540)
			this->removeChild(strengthBar7);
		else if (strength <= 3540 && strength > 2670)
			this->removeChild(strengthBar8);
		else if (strength <= 2670 && strength > 1800)
			this->removeChild(strengthBar9);
		else if (strength <= 1800 && strength > 930)
			this->removeChild(strengthBar10);
		else if (strength <= 930 && strength > 60)
			this->removeChild(strengthBar11);
		else if (strength <= 60 && strength > 0)
		{
			this->removeChild(strengthBar12);
			this->removeChild(strengthBar0);
		}

	}

	//成功
	if (mapType == 1)
	{
		if (map->getPositionX() == -(mapWidth - visibleWidth) && player->getPositionX() == 787)
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();

			//player->setPositionZ(-2);

			this->unscheduleAllSelectors();
			this->removeChild(player);
			auto over = Sprite::create("tipsImg/sucess1.png");
			over->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
			this->addChild(over, 50);

			//下一关
			auto nextItem = MenuItemImage::create(
				NEXT,
				NEXT,
				CC_CALLBACK_1(FirstPassScene::nextCallback, this));
			nextItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
			auto menu3 = Menu::create(nextItem, NULL);
			menu3->setPosition(Vec2::ZERO);
			this->addChild(menu3, 51);

			//重新
			auto replayItem = MenuItemImage::create(
				REPLAY,
				REPLAY,
				CC_CALLBACK_1(FirstPassScene::replayCallback, this));
			replayItem->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
			auto menu4 = Menu::create(replayItem, NULL);
			menu4->setPosition(Vec2::ZERO);
			this->addChild(menu4, 51);

			//结束
			auto endItem = MenuItemImage::create(
				END,
				END,
				CC_CALLBACK_1(FirstPassScene::endCallback, this));
			endItem->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 100));
			auto menu5 = Menu::create(endItem, NULL);
			menu5->setPosition(Vec2::ZERO);
			this->addChild(menu5, 51);

			//小纸条
			if (getPaper == true)
			{
				auto tipsItem = MenuItemImage::create(
					TIP,
					TIP,
					CC_CALLBACK_1(FirstPassScene::tipsCallback, this));
				tipsItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
				auto menu6 = Menu::create(tipsItem, NULL);
				menu6->setPosition(Vec2::ZERO);
				this->addChild(menu6, 51);
			}
		}
	}
	else
	{
		if (map->getPositionX() == 0 && player->getPositionX() == 237)
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();

			//player->setPositionZ(-2);

			this->unscheduleAllSelectors();
			this->removeChild(player);
			auto over = Sprite::create("tipsImg/sucess1.png");
			over->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
			this->addChild(over, 50);

			//下一关
			auto nextItem = MenuItemImage::create(
				NEXT,
				NEXT,
				CC_CALLBACK_1(FirstPassScene::nextCallback, this));
			nextItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
			auto menu3 = Menu::create(nextItem, NULL);
			menu3->setPosition(Vec2::ZERO);
			this->addChild(menu3, 51);

			//重新
			auto replayItem = MenuItemImage::create(
				REPLAY,
				REPLAY,
				CC_CALLBACK_1(FirstPassScene::replayCallback, this));
			replayItem->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
			auto menu4 = Menu::create(replayItem, NULL);
			menu4->setPosition(Vec2::ZERO);
			this->addChild(menu4, 51);

			//结束
			auto endItem = MenuItemImage::create(
				END,
				END,
				CC_CALLBACK_1(FirstPassScene::endCallback, this));
			endItem->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 100));
			auto menu5 = Menu::create(endItem, NULL);
			menu5->setPosition(Vec2::ZERO);
			this->addChild(menu5, 51);

			//小纸条
			if (getPaper == true)
			{
				auto tipsItem = MenuItemImage::create(
					TIP,
					TIP,
					CC_CALLBACK_1(FirstPassScene::tipsCallback, this));
				tipsItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
				auto menu6 = Menu::create(tipsItem, NULL);
				menu6->setPosition(Vec2::ZERO);
				this->addChild(menu6, 51);
			}
		}
	}

	//失败
	if (strength <= 0)
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
		this->unscheduleAllSelectors();
		this->removeChild(player);
		auto over = Sprite::create("tipsImg/gameover2.png");
		over->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(over, 50);

		//重新开始
		auto replayItem = MenuItemImage::create(
			REPLAY,
			REPLAY,
			CC_CALLBACK_1(FirstPassScene::replayCallback, this));
		replayItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
		auto menu3 = Menu::create(replayItem, NULL);
		menu3->setPosition(Vec2::ZERO);
		this->addChild(menu3, 51);

	}
	//CCLOG("ss = %d", strength);
}

void FirstPassScene::addPlayer(Vec2 pos)
{
	// 玩家游泳动画
	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 4; i++)
	{
		auto spriteFrame = SpriteFrame::create(PLAYER_IMG_SWIM_PATH[i], Rect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.2f);	//动画速度
	auto animate = Animate::create(animation);

	// 添加玩家
	auto player = Sprite::create();
	player->setTag(FIRSTSCENE_PLAYER_TAG);
	player->setScale(0.1);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player, 10);
	player->setPosition(pos);
}

void FirstPassScene::replayCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(FirstPassScene::createScene());
	Director::getInstance()->resume();
}

void FirstPassScene::nextCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(SecondPass::createScene());
}

void FirstPassScene::endCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void FirstPassScene::tipsCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(FirstTipScene::createScene());
}

