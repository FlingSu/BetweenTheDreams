//第二关场景
#include"SecondPassScene.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool game_over_flag = false;//su:游戏结束的flag

//su:用于转换成中文字符的函数
std::string GBKToUTF8(const std::string& strGBK)
{
	std::string strOutUTF8 = "";
	WCHAR* str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char* str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}

Scene* SecondPass::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SecondPass::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SecondPass::init()
{
	if (!Layer::init())
	{
		return false;
	}

	m_isJump = false;
	m_jumpDir = Dir::STOP;
	m_jumpSpeed = PLAYER_JUMP_SPEED;
	m_gameOver = false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto colorLayer = LayerColor::create(Color4B(48, 39, 65, 255), visibleSize.width, visibleSize.height);
	colorLayer->setPosition(Vec2(0, 0));
	this->addChild(colorLayer);

	// 加载地图
	loadMap(MAP_TMX_FILE_PATH);

	// 添加玩家
	addPlayer(Vec2(500, 330));//su:定义玩家位置
	addMonster(Vec2(80, 370));//su:定义怪物位置

	//关卡标志
	auto stips = Sprite::create("tipsImg/secondtip.png");
	stips->setPosition(Vec2(80, visibleSize.height-50));
	this->addChild(stips, 20);

	//su:播放音乐
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/pass2bgm.mp3", true);

	// 游戏逻辑
	this->scheduleUpdate();

	// 添加触屏侦听
	addTouchListener();

	return true;
}

void SecondPass::update(float t)
{
	auto player = this->getChildByTag(PLAYER_TAG);
	auto monster = this->getChildByTag(MONSTER_TAG);
	auto map = (TMXTiledMap*)getChildByTag(MAP_TAG);

	// 玩家相对于屏幕的坐标
	float player_screen_x = player->getPositionX();
	float player_screen_y = player->getPositionY() - player->getContentSize().height / 2;

	// 地图相对于屏幕的x坐标
	float map_screen_x = abs(map->getPositionX());
	float map_screen_y = 0;

	// 玩家相对于地图的坐标
	float player_map_x = player_screen_x + map_screen_x;
	float player_map_y = player_screen_y + map_screen_y;

	// 不跳动时遇到非地面图块自动下落
	if ((int)(player_map_y / map->getTileSize().width) >= 0)
	{
		int playerTiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(
			Vec2((int)(player_map_x / map->getTileSize().width), 
				(int)(map->getMapSize().height - 1 - player_map_y / map->getTileSize().height)));
		if ((m_isJump == false) && (m_jumpDir == Dir::STOP) 
			&& (playerTiledID != 27) && (playerTiledID != 29)&& (playerTiledID != 31)
			&& (playerTiledID != 33)//su：遇到33时不下落，与下面不让它前进相对
			&& (playerTiledID != 366) && (playerTiledID != 368) && (playerTiledID != 370))
		{
			m_isJump = true;
			m_jumpDir = Dir::DOWN;
			m_jumpSpeed = 2;
		}
		if (playerTiledID == 453)
		{
			player->setPosition(Vec2(player->getPositionX() + 80, 700));
		}
	}

	// 处理玩家的跳跃
	if (m_isJump)
	{
		if (m_jumpDir == Dir::UP)
		{
			player->setPositionY(player->getPositionY() + m_jumpSpeed);
			m_jumpSpeed -= 2;
			if (m_jumpSpeed <= 0)
			{
				m_jumpDir = Dir::DOWN;
			}
		}
		else if (m_jumpDir == Dir::DOWN)
		{
			// 用于记录玩家是否落到地面上
			bool check = false;

			for (int i = 0; i < m_jumpSpeed; i += 2)
			{

				// 计算当前玩家相对于地图的坐标
				float player_screen_x = player->getPositionX();
				float player_screen_y = player->getPositionY() - player->getContentSize().height / 2 + i;

				// 地图相对于屏幕的x坐标
				float map_screen_x = abs(map->getPositionX());
				float map_screen_y = 0;

				// 玩家相对于地图的坐标
				float player_map_x = player_screen_x + map_screen_x;
				float player_map_y = player_screen_y + map_screen_y;

				// 获取玩家脚下的地图块的编号
				if (player_map_y / map->getTileSize().width >= 0)
				{

					int tiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(
						Vec2((int)(player_map_x / map->getTileSize().width), 
							(int)(map->getMapSize().height - 1 - player_map_y / map->getTileSize().height)));
					if (tiledID == 27 || tiledID == 29 || tiledID == 31 
						|| tiledID == 366 || tiledID == 368 || tiledID == 370)
					{
						check = true;
						player->setPositionY((int)(player_screen_y + player->getContentSize().height / 2 - 6));
						m_jumpSpeed = PLAYER_JUMP_SPEED;
						m_jumpDir = Dir::STOP;
						m_isJump = false;
						break;
					}
					if (tiledID == 472)
					{
						player->setPosition(Vec2(player->getPositionX()+300,700));
						map->getLayer("paper")->setVisible(false);//把纸条的图层设置为不可见
					}
				}

				if (player_screen_y <= -80)
				{
					gameOver();  //角色死亡
				}
			}
			if (!check)
			{
				player->setPositionY(player->getPositionY() - m_jumpSpeed);
				m_jumpSpeed += 2;
				if (m_jumpSpeed > PLAYER_JUMP_SPEED)
				{
					m_jumpSpeed = PLAYER_JUMP_SPEED;
				}
			}
		}
	}

	//处理怪物的运动
	if (monster->getPositionX() > (player->getPositionX()))
	{
		if (monster->getPositionX() > 0)
		{
			monster->setScaleX(-1);
			monster->setPositionX(monster->getPositionX() - 3.5);
		}
	}
	else
	{
		if (monster->getPositionX() < 0)
			monster->setScaleX(1);
		monster->setPositionX(monster->getPositionX() + 0.2);
	}

	// 滚动背景地图
	this->getChildByTag(MAP_TAG)->setPositionX(this->getChildByTag(MAP_TAG)->getPositionX() - 3);
	
	int mapWidth = map->getMapSize().width * map->getTileSize().width;
	int visibleWidth = Director::getInstance()->getWinSize().width;
	//su:
	if (game_over_flag)
	{
		this->unscheduleAllSelectors();
		this->unscheduleUpdate();//撤销定时器，停止滚动背景地图
		player->setVisible(false);
	}
	else
	{
		//replay后需要更新gameoverflag所以要更新这里
		this->scheduleUpdate();
		player->setVisible(true);
	}

	/*int monster_x = player->getPositionX();
	int monster_y = player->getPositionY();
	CCLOG("monster %d,%d", monster_x, monster_y);*/

	//su:碰到怪物或者刷到地图边缘
	if (monster->getBoundingBox().intersectsRect(player->getBoundingBox())
		|| player->getPositionX() <= 0)
	{
		gameOver();
	}

	//su:检测右方遇到的地图块
	if ((int)(player_map_y / map->getTileSize().width) >= 0)
	{
		//su: 在这里瓦片地图使用的坐标系和cocos2dx不一样
		int playerTiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(
			Vec2((int)(player_map_x / map->getTileSize().width),
				(int)(map->getMapSize().height - 2 - player_map_y / map->getTileSize().height)));
		
		//CCLOG("%d\n", playerTiledID);
		
		//su：右方遇到土块不能跑
		if ((playerTiledID == 33))
		{
			player->setPositionX(player->getPositionX()-3);
		}
		//穿过门则游戏成功
		if (playerTiledID == 502 || playerTiledID == 191 || playerTiledID==291)
		{
			success();
		}
	}

	if (map->getPositionX() < -(mapWidth - visibleWidth))
	{
		map->setPositionX(-(mapWidth - visibleWidth));
		// 地图静止后移动角色
		player->setPositionX(player->getPositionX() + 3);
		if (player->getPositionX() > visibleWidth)
		{
			player->setPositionX(visibleWidth);
			this->unscheduleUpdate();
			this->removeChildByTag(PLAYER_TAG);
			if (!game_over_flag)//su:游戏是否已经结束
				success();
			return;
		}
		//地图静止后移动怪物
		monster->setPositionX(monster->getPositionX() + 3);
		if (monster->getPositionX() > visibleWidth)
		{
			monster->setPositionX(visibleWidth);
			this->unscheduleUpdate();
			this->removeChildByTag(MONSTER_TAG);
		}
	}
}

void SecondPass::gameOver()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto tips = Sprite::create(GAME_OVER_TIPS);
	tips->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(tips, 10);
	game_over_flag = true;//su：添加游戏结束标识

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//停止播放音乐
	//重新开始
	auto replayItem = MenuItemImage::create(
		REPLAY2,
		REPLAY2,
		CC_CALLBACK_1(SecondPass::replayCallback, this));
	replayItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
	auto menu3 = Menu::create(replayItem, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 51);
}

void SecondPass::addPlayer(Vec2 pos)
{
	// 玩家跑动动画
	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 3; i++)
	{
		auto spriteFrame = SpriteFrame::create(PLAYER_IMG_PATH[i], Rect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);

	// 添加玩家
	auto player = Sprite::create();
	player->setTag(PLAYER_TAG);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player, 10);
	player->setPosition(pos);
}

void SecondPass::addMonster(Vec2 pos)
{
	// 玩家跑动动画
	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 4; i++)
	{
		auto spriteFrame = SpriteFrame::create(MONSTER_IMG_PATH[i], Rect(0, 0, MONSTER_WIDTH, MONSTER_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.12f);
	auto animate = Animate::create(animation);

	// 添加怪物
	auto player = Sprite::create();
	player->setTag(MONSTER_TAG);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player, 10);
	player->setPosition(pos);
}

void SecondPass::loadMap(std::string mapPath)
{
	// 加载地图
	auto map = TMXTiledMap::create(mapPath);
	if (map != NULL)
	{
		this->addChild(map, 2);
		map->setTag(MAP_TAG);
		map->setPosition(Vec2(0, 0));
	}
	else
	{
		CCLOG("load map failed!");
		return;
	}
}

void SecondPass::addTouchListener()
{
	// 加入触摸的处理
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SecondPass::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void SecondPass::success()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto over = Sprite::create("tipsImg/success.png");
	over->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(over, 50);

	//下一关
	auto nextItem = MenuItemImage::create(
		NEXT2,
		NEXT2,
		CC_CALLBACK_1(SecondPass::nextCallback, this));
	nextItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
	auto menu3 = Menu::create(nextItem, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 51);

	//重新
	auto replayItem = MenuItemImage::create(
		REPLAY2,
		REPLAY2,
		CC_CALLBACK_1(SecondPass::replayCallback, this));
	replayItem->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	auto menu4 = Menu::create(replayItem, NULL);
	menu4->setPosition(Vec2::ZERO);
	this->addChild(menu4, 51);

	//结束
	auto endItem = MenuItemImage::create(
		END2,
		END2,
		CC_CALLBACK_1(SecondPass::endCallback, this));
	endItem->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 100));
	auto menu5 = Menu::create(endItem, NULL);
	menu5->setPosition(Vec2::ZERO);
	this->addChild(menu5, 51);

	auto map = (TMXTiledMap*)getChildByTag(MAP_TAG);
	if (!map->getLayer("paper")->isVisible())
	{
		auto tipsItem = MenuItemImage::create(
			TIP2,
			TIP2,
			CC_CALLBACK_1(SecondPass::tipsCallback, this));
		tipsItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));
		auto menu6 = Menu::create(tipsItem, NULL);
		menu6->setPosition(Vec2::ZERO);
		this->addChild(menu6, 51);
	}
	
		
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//停止播放音乐
	game_over_flag = true;//su：添加游戏结束标识
}

bool SecondPass::onTouchBegan(Touch* touch, Event* unused_event)
{
	if (!this->m_isJump) {
		m_isJump = true;
		m_jumpDir = Dir::UP;
	}
	return true;
}

void SecondPass::replayCallback(Ref* pSender)
{
	game_over_flag = false;
	Director::getInstance()->replaceScene(SecondPass::createScene());
	Director::getInstance()->resume();
}

void SecondPass::nextCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(ThirdPassScene::createScene());//pass3
}

void SecondPass::endCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void SecondPass::tipsCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(SecondTipScene::createScene());
}


