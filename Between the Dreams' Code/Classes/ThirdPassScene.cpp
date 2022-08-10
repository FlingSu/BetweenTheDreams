//第三关场景
#include"ThirdPassScene.h"
#include"SecondPassScene.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

Menu* menu_1a;
Menu* menu_1b;
Menu* menu_1c;
Menu* menu_1d;
Label* answer1;
Menu* menu_2a;
Menu* menu_2b;
Menu* menu_2c;
Menu* menu_2d;
Label* answer2;

bool answer_correct;
bool answer_error;

Label* count11;

Color3B PressColor = Color3B(0, 0, 0);

cocos2d::Scene* ThirdPassScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ThirdPassScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool ThirdPassScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    answer_correct = false;
    answer_error = false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*auto colorLayer = LayerColor::create(Color4B(255, 255, 255, 255), visibleSize.width, visibleSize.height);
    colorLayer->setPosition(Vec2(0, 0));
    this->addChild(colorLayer);*/

	//播放音乐
	auto audioengine = SimpleAudioEngine::getInstance();
	audioengine->playBackgroundMusic("bgm/pass3bgm.mp3", true);

	//exam paper
	auto paper = Sprite::create("thirdPassresource/exam.png");
    paper->setScale(0.63);
    paper->setPosition(Vec2(visibleSize.width / 2+235, visibleSize.height / 2-20));
	this->addChild(paper, 50);

	float a1sPosition = visibleSize.height / 2 - 20;
	float a1sPositionPlus = 120;
	//1 a
	auto button_1a = MenuItemImage::create(
		"thirdPassresource/1a.png",
		"thirdPassresource/1aa.png", "thirdPassresource/1aa.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_1a, this));
	button_1a->setPosition(Vec2(visibleSize.width / 2+35, a1sPosition));
	button_1a->setScale(0.43);
	menu_1a = Menu::create(button_1a, NULL);
	menu_1a->setPosition(Vec2::ZERO);
	menu_1a->setTag(61);
	this->addChild(menu_1a, 51);

	//1 b
	auto button_1b = MenuItemImage::create(
		"thirdPassresource/1b.png",
		"thirdPassresource/1bb.png", "thirdPassresource/1bb.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_1b, this));
	button_1b->setPosition(Vec2(button_1a->getPositionX()+a1sPositionPlus, a1sPosition));
	button_1b->setScale(0.43);
	menu_1b = Menu::create(button_1b, NULL);
	menu_1b->setPosition(Vec2::ZERO);
	menu_1b->setTag(62);
	this->addChild(menu_1b, 51);

	//1 c
	auto button_1c = MenuItemImage::create(
		"thirdPassresource/1c.png",
		"thirdPassresource/1cc.png", "thirdPassresource/1cc.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_1c, this));
	button_1c->setPosition(Vec2(button_1b->getPositionX()+a1sPositionPlus, a1sPosition));
	button_1c->setScale(0.43);
	menu_1c = Menu::create(button_1c, NULL);
	menu_1c->setPosition(Vec2::ZERO);
	menu_1c->setTag(63);
	this->addChild(menu_1c, 51);

	//1 d
	auto button_1d = MenuItemImage::create(
		"thirdPassresource/1d.png",
		"thirdPassresource/1dd.png", "thirdPassresource/1dd.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_1d, this));
	button_1d->setPosition(Vec2(button_1c->getPositionX()+a1sPositionPlus, a1sPosition));
	button_1d->setScale(0.43);
	menu_1d = Menu::create(button_1d, NULL);
	menu_1d->setPosition(Vec2::ZERO);
	menu_1d->setTag(64);
	this->addChild(menu_1d, 51);

	//2 的固定x位置以及 列间距
	float a2sPosition = visibleSize.width / 2 + 200;
	float a2sPositionMinus = 45;
	//2 a
	auto button_2a = MenuItemImage::create(
		"thirdPassresource/2a.png",
		"thirdPassresource/2aa.png", "thirdPassresource/2aa.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_2a, this));
	button_2a->setPosition(Vec2(a2sPosition, visibleSize.height / 2 - 165));
	button_2a->setScale(0.5);
	menu_2a = Menu::create(button_2a, NULL);
	menu_2a->setPosition(Vec2::ZERO);
	menu_2a->setTag(71);
	this->addChild(menu_2a, 51);

	//2 b
	auto button_2b = MenuItemImage::create(
		"thirdPassresource/2b.png",
		"thirdPassresource/2bb.png", "thirdPassresource/2bb.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_2b, this));
	button_2b->setPosition(Vec2(a2sPosition, button_2a->getPositionY()- a2sPositionMinus));
	button_2b->setScale(0.5);
	menu_2b = Menu::create(button_2b, NULL);
	menu_2b->setPosition(Vec2::ZERO);
	menu_2b->setTag(72);
	this->addChild(menu_2b, 51);

	//2 c
	auto button_2c = MenuItemImage::create(
		"thirdPassresource/2c.png",
		"thirdPassresource/2cc.png", "thirdPassresource/2cc.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_2c, this));
	button_2c->setPosition(Vec2(a2sPosition, button_2b->getPositionY()- a2sPositionMinus));
	button_2c->setScale(0.5);
	menu_2c = Menu::create(button_2c, NULL);
	menu_2c->setPosition(Vec2::ZERO);
	menu_2c->setTag(73);
	this->addChild(menu_2c, 51);

	//2 d
	auto button_2d = MenuItemImage::create(
		"thirdPassresource/2d.png",
		"thirdPassresource/2dd.png", "thirdPassresource/2dd.png",
		CC_CALLBACK_1(ThirdPassScene::onClick_2d, this));
	button_2d->setPosition(Vec2(a2sPosition, button_2c->getPositionY()-a2sPositionMinus));
	button_2d->setScale(0.5);
	menu_2d = Menu::create(button_2d, NULL);
	menu_2d->setPosition(Vec2::ZERO);
	menu_2d->setTag(74);
	this->addChild(menu_2d, 51);

	//对选择的答案进行初始化
	answer1 = Label::createWithTTF("", "fonts/Marker Felt.ttf", 45);
	//answer1->setString("B");
	answer1->setPosition(Vec2(visibleSize.width-420, visibleSize.height/2+10));
	answer1->setColor(PressColor);
	this->addChild(answer1,52);

	answer2 = Label::createWithTTF("", "fonts/Marker Felt.ttf", 45);
	//answer2->setString("B");
	answer2->setPosition(Vec2(visibleSize.width/2 +200, visibleSize.height / 2 - 130));
	answer2->setColor(PressColor);
	this->addChild(answer2, 52);

	//添加动画
	addAnimation(Vec2(visibleSize.width/2-50,visibleSize.height/2));

	//添加倒计时
	m_timer = GameTimer::createTimer(60);//60s
	m_timer->setPosition(100, 200);
	m_timer->setTag(233);
	
	this->addChild(m_timer, 55);

	// 游戏逻辑
	this->scheduleUpdate();

    return true;
}

void ThirdPassScene::update(float t)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (answer_correct)
	{
		menu_1a->setEnabled(false);
		menu_1b->setEnabled(false);
		menu_1c->setEnabled(false);
		menu_1d->setEnabled(false);
	}
	
	if (answer_error)
	{
		addAnimationError(Vec2(visibleSize.width / 2 - 50, visibleSize.height / 2));
		gameOver();
		menu_1a->setEnabled(false);
		menu_1b->setEnabled(false);
		menu_1c->setEnabled(false);
		menu_1d->setEnabled(false);

		menu_2a->setEnabled(false);
		menu_2b->setEnabled(false);
		menu_2c->setEnabled(false);
		menu_2d->setEnabled(false);
		this->unscheduleUpdate();
	}
	//CCLOG("ptr %f\n", m_timer->getPtime());
	
	
	if (!m_timer->getPtime() && answer_correct)
	{
		//CCLOG("ptr %d",testtheTime);
		addAnimationPass(Vec2(visibleSize.width / 2 - 50, visibleSize.height / 2));
		gameSuccess();
		menu_1a->setEnabled(false);
		menu_1b->setEnabled(false);
		menu_1c->setEnabled(false);
		menu_1d->setEnabled(false);

		menu_2a->setEnabled(false);
		menu_2b->setEnabled(false);
		menu_2c->setEnabled(false);
		menu_2d->setEnabled(false);
		this->unscheduleUpdate();
	}
	else if(!m_timer->getPtime())
	{
		addAnimationError(Vec2(visibleSize.width / 2 - 50, visibleSize.height / 2));
		gameOver();
		menu_1a->setEnabled(false);
		menu_1b->setEnabled(false);
		menu_1c->setEnabled(false);
		menu_1d->setEnabled(false);

		menu_2a->setEnabled(false);
		menu_2b->setEnabled(false);
		menu_2c->setEnabled(false);
		menu_2d->setEnabled(false);
		this->unscheduleUpdate();
	}
}

void ThirdPassScene::addAnimation(Vec2 pos)
{
	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 4; i++)
	{
		auto spriteFrame = SpriteFrame::create(ANIMATION_IMG_PATH[i], Rect(0, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(15.0f);//15s 换一帧
	auto animate = Animate::create(animation);

	// 添加玩家
	auto player = Sprite::create();
	player->setTag(ANIMATION_TAG);
	player->runAction(animate);
	this->addChild(player, 10);
	player->setPosition(pos);
}

void ThirdPassScene::addAnimationPass(Vec2 pos)
{

	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 2; i++)
	{
		auto spriteFrame = SpriteFrame::create(ANIMATIONPASS_IMG_PATH[i], Rect(0, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.4f);//0.5s 换一帧
	animation->setRestoreOriginalFrame(true);
	auto animate = Animate::create(animation);

	// 添加玩家
	auto player = Sprite::create();
	player->setTag(ANIMATIONPASS_TAG);
	player->runAction(RepeatForever::create(animate));
	this->addChild(player, 10);
	player->setPosition(pos);

	//撤销原来的动画
	this->removeChildByTag(ANIMATION_TAG);
}

void ThirdPassScene::addAnimationError(Vec2 pos)
{
	//撤销原来的动画
	this->removeChildByTag(ANIMATION_TAG);

	Vector<SpriteFrame* >frameVector;
	for (int i = 0; i < 2; i++)
	{
		auto spriteFrame = SpriteFrame::create(ANIMATIONERROR_IMG_PATH[i], 
			Rect(0, 0, ANIMATION_WIDTH, ANIMATION_HEIGHT));
		frameVector.pushBack(spriteFrame);
	}
	auto animation = Animation::createWithSpriteFrames(frameVector);
	animation->setDelayPerUnit(0.4f);//0.5s 换一帧
	animation->setLoops(1);//只循环一轮
	auto animate = Animate::create(animation);

	// 添加玩家
	auto player = Sprite::create();
	player->setTag(ANIMATIONERROR_TAG);
	player->runAction(animate);
	this->addChild(player, 10);
	player->setPosition(pos);
}

void ThirdPassScene::onClick_1a(Ref* sender)
{
	answer_error = true;
	answer1->setString("A");
}

void ThirdPassScene::onClick_1b(Ref* sender)
{
	answer_correct = true;
	answer1->setString("B");
}

void ThirdPassScene::onClick_1c(Ref* sender)
{
	answer_correct = true;
	answer1->setString("C");
}

void ThirdPassScene::onClick_1d(Ref* sender)
{
	answer_correct = true;
	answer1->setString("D");
}

void ThirdPassScene::onClick_2a(Ref* sender)
{
	answer_error = true;
	answer2->setString("A");
}

void ThirdPassScene::onClick_2b(Ref* sender)
{
	answer_error = true;
	answer2->setString("B");
}

void ThirdPassScene::onClick_2c(Ref* sender)
{
	answer_error = true;
	answer2->setString("C");
}

void ThirdPassScene::onClick_2d(Ref* sender)
{
	answer_error = true;
	answer2->setString("D");
}

void ThirdPassScene::gameOver()
{
	
	//游戏失败图标
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto tips = Sprite::create(GAME_OVER_TIPS3);
	tips->setPosition(Vec2(250, visibleSize.height / 2+70));
	this->addChild(tips, 88);

	SimpleAudioEngine::getInstance()->stopBackgroundMusic();//停止播放音乐
	//重新开始
	auto replayItem = MenuItemImage::create(
		REPLAY2,
		REPLAY2,
		CC_CALLBACK_1(ThirdPassScene::replayCallback, this));
	replayItem->setPosition(Vec2(visibleSize.width-50, visibleSize.height -50));
	auto menu3 = Menu::create(replayItem, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 51);

	//结束
	auto endItem = MenuItemImage::create(
		END2,
		END2,
		CC_CALLBACK_1(ThirdPassScene::endCallback, this));
	endItem->setPosition(Vec2(visibleSize.width - 150, visibleSize.height-50));
	auto menu5 = Menu::create(endItem, NULL);
	menu5->setPosition(Vec2::ZERO);
	this->addChild(menu5, 51);
}

void ThirdPassScene::gameSuccess()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto tips = Sprite::create(GAME_PASSALL);
	tips->setPosition(Vec2(visibleSize.width / 2 + 235, visibleSize.height / 2));
	this->addChild(tips, 88);


	//exam paper
	auto paper = Sprite::create("thirdPassresource/examc.png");
	paper->setScale(0.63);
	paper->setPosition(Vec2(visibleSize.width / 2 + 235, visibleSize.height / 2 - 20));
	this->addChild(paper, 87);

	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/end.mp3", true);

	//结束
	auto endItem = MenuItemImage::create(
		END2,
		END2,
		CC_CALLBACK_1(ThirdPassScene::endCallback, this));
	endItem->setPosition(Vec2(visibleSize.width - 150, visibleSize.height - 50));
	auto menu5 = Menu::create(endItem, NULL);
	menu5->setPosition(Vec2::ZERO);
	this->addChild(menu5, 51);

	//重新开始
	auto replayItem = MenuItemImage::create(
		REPLAY2,
		REPLAY2,
		CC_CALLBACK_1(ThirdPassScene::replayCallback, this));
	replayItem->setPosition(Vec2(visibleSize.width - 50, visibleSize.height - 50));
	auto menu3 = Menu::create(replayItem, NULL);
	menu3->setPosition(Vec2::ZERO);
	this->addChild(menu3, 51);

	auto label = Label::createWithTTF(GBKToUTF8("ps: 有时候捕梦者也需要打破常规"),
		"fonts/tangyuan.ttf", 35);
	label->setPosition(Vec2(visibleSize.width / 2 + 235, 150));
	label->setColor(Color3B::BLACK);
	this->addChild(label, 88);
}

void ThirdPassScene::replayCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(ThirdPassScene::createScene());
	Director::getInstance()->resume();
}

void ThirdPassScene::endCallback(Ref* pSender)
{
	Director::getInstance()->end();
}




