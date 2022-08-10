//�ڶ��س���
#include"SecondPassScene.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

bool game_over_flag = false;//su:��Ϸ������flag

//su:����ת���������ַ��ĺ���
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

	// ���ص�ͼ
	loadMap(MAP_TMX_FILE_PATH);

	// ������
	addPlayer(Vec2(500, 330));//su:�������λ��
	addMonster(Vec2(80, 370));//su:�������λ��

	//�ؿ���־
	auto stips = Sprite::create("tipsImg/secondtip.png");
	stips->setPosition(Vec2(80, visibleSize.height-50));
	this->addChild(stips, 20);

	//su:��������
	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/pass2bgm.mp3", true);

	// ��Ϸ�߼�
	this->scheduleUpdate();

	// ��Ӵ�������
	addTouchListener();

	return true;
}

void SecondPass::update(float t)
{
	auto player = this->getChildByTag(PLAYER_TAG);
	auto monster = this->getChildByTag(MONSTER_TAG);
	auto map = (TMXTiledMap*)getChildByTag(MAP_TAG);

	// ����������Ļ������
	float player_screen_x = player->getPositionX();
	float player_screen_y = player->getPositionY() - player->getContentSize().height / 2;

	// ��ͼ�������Ļ��x����
	float map_screen_x = abs(map->getPositionX());
	float map_screen_y = 0;

	// �������ڵ�ͼ������
	float player_map_x = player_screen_x + map_screen_x;
	float player_map_y = player_screen_y + map_screen_y;

	// ������ʱ�����ǵ���ͼ���Զ�����
	if ((int)(player_map_y / map->getTileSize().width) >= 0)
	{
		int playerTiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(
			Vec2((int)(player_map_x / map->getTileSize().width), 
				(int)(map->getMapSize().height - 1 - player_map_y / map->getTileSize().height)));
		if ((m_isJump == false) && (m_jumpDir == Dir::STOP) 
			&& (playerTiledID != 27) && (playerTiledID != 29)&& (playerTiledID != 31)
			&& (playerTiledID != 33)//su������33ʱ�����䣬�����治����ǰ�����
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

	// ������ҵ���Ծ
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
			// ���ڼ�¼����Ƿ��䵽������
			bool check = false;

			for (int i = 0; i < m_jumpSpeed; i += 2)
			{

				// ���㵱ǰ�������ڵ�ͼ������
				float player_screen_x = player->getPositionX();
				float player_screen_y = player->getPositionY() - player->getContentSize().height / 2 + i;

				// ��ͼ�������Ļ��x����
				float map_screen_x = abs(map->getPositionX());
				float map_screen_y = 0;

				// �������ڵ�ͼ������
				float player_map_x = player_screen_x + map_screen_x;
				float player_map_y = player_screen_y + map_screen_y;

				// ��ȡ��ҽ��µĵ�ͼ��ı��
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
						map->getLayer("paper")->setVisible(false);//��ֽ����ͼ������Ϊ���ɼ�
					}
				}

				if (player_screen_y <= -80)
				{
					gameOver();  //��ɫ����
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

	//���������˶�
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

	// ����������ͼ
	this->getChildByTag(MAP_TAG)->setPositionX(this->getChildByTag(MAP_TAG)->getPositionX() - 3);
	
	int mapWidth = map->getMapSize().width * map->getTileSize().width;
	int visibleWidth = Director::getInstance()->getWinSize().width;
	//su:
	if (game_over_flag)
	{
		this->unscheduleAllSelectors();
		this->unscheduleUpdate();//������ʱ����ֹͣ����������ͼ
		player->setVisible(false);
	}
	else
	{
		//replay����Ҫ����gameoverflag����Ҫ��������
		this->scheduleUpdate();
		player->setVisible(true);
	}

	/*int monster_x = player->getPositionX();
	int monster_y = player->getPositionY();
	CCLOG("monster %d,%d", monster_x, monster_y);*/

	//su:�����������ˢ����ͼ��Ե
	if (monster->getBoundingBox().intersectsRect(player->getBoundingBox())
		|| player->getPositionX() <= 0)
	{
		gameOver();
	}

	//su:����ҷ������ĵ�ͼ��
	if ((int)(player_map_y / map->getTileSize().width) >= 0)
	{
		//su: ��������Ƭ��ͼʹ�õ�����ϵ��cocos2dx��һ��
		int playerTiledID = map->getLayer(MAP_BG_LAYER_NAME)->getTileGIDAt(
			Vec2((int)(player_map_x / map->getTileSize().width),
				(int)(map->getMapSize().height - 2 - player_map_y / map->getTileSize().height)));
		
		//CCLOG("%d\n", playerTiledID);
		
		//su���ҷ��������鲻����
		if ((playerTiledID == 33))
		{
			player->setPositionX(player->getPositionX()-3);
		}
		//����������Ϸ�ɹ�
		if (playerTiledID == 502 || playerTiledID == 191 || playerTiledID==291)
		{
			success();
		}
	}

	if (map->getPositionX() < -(mapWidth - visibleWidth))
	{
		map->setPositionX(-(mapWidth - visibleWidth));
		// ��ͼ��ֹ���ƶ���ɫ
		player->setPositionX(player->getPositionX() + 3);
		if (player->getPositionX() > visibleWidth)
		{
			player->setPositionX(visibleWidth);
			this->unscheduleUpdate();
			this->removeChildByTag(PLAYER_TAG);
			if (!game_over_flag)//su:��Ϸ�Ƿ��Ѿ�����
				success();
			return;
		}
		//��ͼ��ֹ���ƶ�����
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
	game_over_flag = true;//su�������Ϸ������ʶ

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//ֹͣ��������
	//���¿�ʼ
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
	// ����ܶ�����
	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 3; i++)
	{
		auto spriteFrame = SpriteFrame::create(PLAYER_IMG_PATH[i], Rect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.08f);
	auto animate = Animate::create(animation);

	// ������
	auto player = Sprite::create();
	player->setTag(PLAYER_TAG);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player, 10);
	player->setPosition(pos);
}

void SecondPass::addMonster(Vec2 pos)
{
	// ����ܶ�����
	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 4; i++)
	{
		auto spriteFrame = SpriteFrame::create(MONSTER_IMG_PATH[i], Rect(0, 0, MONSTER_WIDTH, MONSTER_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.12f);
	auto animate = Animate::create(animation);

	// ��ӹ���
	auto player = Sprite::create();
	player->setTag(MONSTER_TAG);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player, 10);
	player->setPosition(pos);
}

void SecondPass::loadMap(std::string mapPath)
{
	// ���ص�ͼ
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
	// ���봥���Ĵ���
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

	//��һ��
	auto nextItem = MenuItemImage::create(
		NEXT2,
		NEXT2,
		CC_CALLBACK_1(SecondPass::nextCallback, this));
	nextItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 100));
	auto menu3 = Menu::create(nextItem, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 51);

	//����
	auto replayItem = MenuItemImage::create(
		REPLAY2,
		REPLAY2,
		CC_CALLBACK_1(SecondPass::replayCallback, this));
	replayItem->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	auto menu4 = Menu::create(replayItem, NULL);
	menu4->setPosition(Vec2::ZERO);
	this->addChild(menu4, 51);

	//����
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
	
		
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//ֹͣ��������
	game_over_flag = true;//su�������Ϸ������ʶ
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


