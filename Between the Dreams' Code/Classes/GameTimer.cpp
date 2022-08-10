#include "GameTimer.h"

GameTimer* GameTimer::createTimer(float time)
{
	GameTimer* gametimer = new GameTimer;
	if (gametimer && gametimer->init(time))
	{
		gametimer->autorelease();
		return gametimer;
	}
	else
	{
		delete gametimer;
		gametimer = NULL;
	}
	return NULL;
}

void GameTimer::update(float delta)
{
	if (pTime > 0.0)
		pTime -= delta;
	if (pTime <= 0.0)
	{
		//testtheTime = true;
		//if(testtheTime)
		pTime = 0;
		CCLOG("pTime %d", pTime);
		this->unscheduleAllSelectors();
		return;
	}
	char* mtime = new char[10];

	if (pTime < 10)
		count->setColor(Color3B::RED);
	count->setString(StringUtils::format("%02d : %02d", (int)pTime / 60, (int)pTime % 60));

	//此处只是显示分钟数和秒数  自己可以定义输出时间格式
	//sprintf(mtime, "%d : %d", (int)pTime / 60, (int)pTime % 60);
	//label->setString(mtime);
}

bool GameTimer::init(float time)
{
	pTime = time;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	count = Label::createWithTTF(StringUtils::format("%d : %d", (int)pTime / 60, (int)pTime % 60), "fonts/STHUPO.ttf", 40);
	count->setPosition(Vec2(visibleSize.width/2-50, visibleSize.height/2+150));
	count->setColor(Color3B::YELLOW);
	this->addChild(count, 1);

	schedule(schedule_selector(GameTimer::update));

	return true;
}

float GameTimer::getPtime()
{
	return pTime;
}
