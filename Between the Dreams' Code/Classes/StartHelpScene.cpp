#include "StartHelpScene.h"
#include "SecondPassScene.h"
#include "StartScene.h"
#include "config_set.h"

#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

cocos2d::Scene* StartHelpScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = StartHelpScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool StartHelpScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto audioengine = SimpleAudioEngine::getInstance();
    audioengine->playBackgroundMusic("bgm/startbgm.mp3", true);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto nextItem = MenuItemImage::create(
        "tipsImg/back.png",
        "tipsImg/back.png",
        CC_CALLBACK_1(StartHelpScene::BackCallback, this));
    nextItem->setPosition(Vec2(70, 70));
    nextItem->setScale(0.3);
    auto menu3 = Menu::create(nextItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);
    
    auto label = Label::createWithTTF(GBKToUTF8("�ؿ�˵����"),
        "fonts/tangyuan.ttf",50);
    label->setPosition(Vec2(visibleSize.width/2, visibleSize.height-150));
    this->addChild(label, 1);

    auto label_1 = Label::createWithTTF(GBKToUTF8("��һ�أ�ͨ���ٿ�ҡ�˿��Ʋ����ߵ�\n�˶�����"),
        "fonts/tangyuan.ttf", 40);
    label_1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height -300));
    this->addChild(label_1, 1);

    auto label_2 = Label::createWithTTF(GBKToUTF8("�ڶ��أ�ͨ�������Ļʹ��������Ծ"),
        "fonts/tangyuan.ttf", 40);
    label_2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 400));
    this->addChild(label_2, 1);

    auto label_3 = Label::createWithTTF(GBKToUTF8("�����أ�ͨ�����ѡ��ѡ����Ĵ𰸣�\nÿ����ֻ��ѡ��һ�Σ�"),
        "fonts/tangyuan.ttf", 40);
    label_3->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 500));
    this->addChild(label_3, 1);
}

void StartHelpScene::BackCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(StartScene::createScene());
}
