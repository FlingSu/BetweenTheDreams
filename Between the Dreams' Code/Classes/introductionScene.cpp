#include "introductionScene.h"

#include "FirstPassScene.h"
#include "SecondPassScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene* introductionScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = introductionScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool introductionScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto audioengine = SimpleAudioEngine::getInstance();
    audioengine->playBackgroundMusic("bgm/1.mp3",false);

    //1
    auto label_1 = Label::createWithTTF(GBKToUTF8("嗨，捕梦者"),
        "fonts/tangyuan.ttf", 40);
    label_1->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_1, 1);

    auto delay_1 = DelayTime::create(0);
    auto seq_1 = Sequence::create(/*MoveBy::create(0.2f,Point(visibleSize.width / 2, -100)),*/ delay_1,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_1->runAction(seq_1);

    //2
    auto label_2 = Label::createWithTTF(GBKToUTF8("我在这里等你很久了"),
        "fonts/tangyuan.ttf", 40);
    label_2->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_2, 1);

    auto delay_2 = DelayTime::create(1);
    auto seq_2 = Sequence::create(/*MoveBy::create(0.2f, Point(visibleSize.width / 2, -100)),*/ delay_2,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_2->runAction(seq_2);

    //3
    auto label_3 = Label::createWithTTF(GBKToUTF8("我是谁？"),
        "fonts/tangyuan.ttf", 40);
    label_3->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_3, 1);

    auto delay_3 = DelayTime::create(2);
    auto seq_3 = Sequence::create(/*MoveBy::create(0.2f, Point(visibleSize.width / 2, -100)),*/ delay_3,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_3->runAction(seq_3);

    //4
    auto label_4 = Label::createWithTTF(GBKToUTF8("哈哈，这不重要"),
        "fonts/tangyuan.ttf", 40);
    label_4->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_4, 1);

    auto delay_4 = DelayTime::create(3);
    auto seq_4 = Sequence::create(/*MoveBy::create(0.2f, Point(visibleSize.width / 2, -100)), */delay_4,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_4->runAction(seq_4);

    //5
    auto label_5 = Label::createWithTTF(GBKToUTF8("很久以前也有人来到这里"),
        "fonts/tangyuan.ttf", 40);
    label_5->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_5, 1);

    auto delay_5 = DelayTime::create(4);
    auto seq_5 = Sequence::create(/*MoveBy::create(0.2f, Point(visibleSize.width / 2, -100)), */delay_5,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_5->runAction(seq_5);

    //6
    auto label_6 = Label::createWithTTF(GBKToUTF8("我为他准备的梦境是化成一只蝴蝶"),
        "fonts/tangyuan.ttf", 40);
    label_6->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_6, 1);

    auto delay_6 = DelayTime::create(5);
    auto seq_6 = Sequence::create(/*MoveBy::create(0.2f, Point(visibleSize.width / 2, -100)), */delay_6,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_6->runAction(seq_6);

    //7
    auto label_7 = Label::createWithTTF(GBKToUTF8("翩翩飞舞于鲜美芳草，落英缤纷之间"),
        "fonts/tangyuan.ttf", 40);
    label_7->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_7, 1);

    auto delay_7 = DelayTime::create(6);
    auto seq_7 = Sequence::create(/*MoveBy::create(0.2f, Point(visibleSize.width / 2, -100)), */delay_7,
        MoveTo::create(13.5f, Point(visibleSize.width / 2, visibleSize.height + 100)), nullptr);
    label_7->runAction(seq_7);

    //-------------------------------分割线-----------------------------------------------------

    //8
    auto label_8 = Label::createWithTTF(GBKToUTF8("距离上一次......"),
        "fonts/tangyuan.ttf", 40);
    label_8->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_8, 1);

    auto delay_8 = DelayTime::create(8);
    auto seq_8 = Sequence::create(/*MoveBy::create(0.0f, Point(visibleSize.width / 2, -100)),*/ delay_8,
        MoveTo::create(10.0f, Point(visibleSize.width / 2, visibleSize.height - 100)), nullptr);
    label_8->runAction(seq_8);

    //9
    auto label_9 = Label::createWithTTF(GBKToUTF8("已经太久没人来了啊"),
        "fonts/tangyuan.ttf", 40);
    label_9->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_9, 1);

    auto delay_9 = DelayTime::create(9);
    auto seq_9 = Sequence::create(/*MoveBy::create(0.0f, Point(visibleSize.width / 2, -100)),*/ delay_9,
        MoveTo::create(9.0f, Point(visibleSize.width / 2, visibleSize.height - 200)), nullptr);
    label_9->runAction(seq_9);

    //10
    auto label_10 = Label::createWithTTF(GBKToUTF8("不过我已经为你准备好了三个梦境"),
        "fonts/tangyuan.ttf", 40);
    label_10->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_10, 1);

    auto delay_10 = DelayTime::create(10);
    auto seq_10 = Sequence::create(/*MoveBy::create(0.0f, Point(visibleSize.width / 2, -100)),*/ delay_10,
        MoveTo::create(8.0f, Point(visibleSize.width / 2, visibleSize.height - 300)), nullptr);
    label_10->runAction(seq_10);

    //11
    auto label_11 = Label::createWithTTF(GBKToUTF8("梦中所见皆所得"),
        "fonts/tangyuan.ttf", 40);
    label_11->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_11, 1);

    auto delay_11 = DelayTime::create(11);
    auto seq_11 = Sequence::create(/*MoveBy::create(0.0f, Point(visibleSize.width / 2, -100)),*/ delay_11,
        MoveTo::create(7.0f, Point(visibleSize.width / 2, visibleSize.height - 400)), nullptr);
    label_11->runAction(seq_11);

    //12
    auto label_12 = Label::createWithTTF(GBKToUTF8("现在"),
        "fonts/tangyuan.ttf", 40);
    label_12->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_12, 1);

    auto delay_12 = DelayTime::create(12);
    auto seq_12 = Sequence::create(/*MoveBy::create(0.0f, Point(visibleSize.width / 2, -100)), */delay_12,
        MoveTo::create(6.0f, Point(visibleSize.width / 2, visibleSize.height - 500)), nullptr);
    label_12->runAction(seq_12);

    //13
    auto label_13 = Label::createWithTTF(GBKToUTF8("就请入梦吧"),
        "fonts/tangyuan.ttf", 40);
    label_13->setPosition(Vec2(visibleSize.width / 2, -100));
    this->addChild(label_13, 1);

    auto delay_13 = DelayTime::create(13);
    auto seq_13 = Sequence::create(/*MoveBy::create(0.0f, Point(visibleSize.width / 2, -100)), */delay_13,
        MoveTo::create(5.0f, Point(visibleSize.width / 2, visibleSize.height - 600)), nullptr);
    label_13->runAction(seq_13);

    //在屏幕底端中央显示闪烁的操作提示
    auto playTip = LabelTTF::create(GBKToUTF8("点击屏幕继续游戏"), "SIMLI", 30);
    playTip->setPosition(visibleSize.width / 2, 50);
    playTip->setVisible(false);
    this->addChild(playTip, 1);

    auto delay = DelayTime::create(26);
    auto seq = Sequence::create(FadeIn::create(3.0), delay, Blink::create(10, 12), nullptr);
    //auto blink = Blink::create(8, 10);
    playTip->runAction(seq);

    // 加入触摸的处理
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(introductionScene::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

}



bool introductionScene::onTouchBegan(Touch* touch, Event* unused_event)
{
    Director::getInstance()->replaceScene(FirstPassScene::createScene());
    return true;
}
