#ifndef _GAME_TIMER_H_
#define _GAME_TIMER_H_

#include "cocos2d.h"
#include "config_set.h"

USING_NS_CC;

class GameTimer : public cocos2d::Node
{
public:
	static GameTimer* createTimer(float time);

	void update(float delta);

	bool init(float time);

	float getPtime();

	//private:
	LabelTTF* label;
	float	pTime;
	Label* count;
};

#endif
