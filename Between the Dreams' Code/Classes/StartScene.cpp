//开始菜单界面
#include "StartScene.h"
#include "FirstPassScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include"introductionScene.h"
#include "StartHelpScene.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace CocosDenshion;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool StartScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm/startbgm.mp3");

    auto audioengine = SimpleAudioEngine::getInstance();
    audioengine->playBackgroundMusic("bgm/startbgm.mp3", true);

    auto back = Sprite::create("StartScene/startImg.png");
    back->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(back,2);

    //帮助
    auto helpItem = MenuItemImage::create(
        "StartScene/help.png",
        "StartScene/help.png",
        CC_CALLBACK_1(StartScene::helpCallback, this));
    helpItem->setPosition(Vec2(visibleSize.width / 2 + 220, visibleSize.height / 2 - 70));
    auto menu4 = Menu::create(helpItem, NULL);
    menu4->setPosition(Vec2::ZERO);
    this->addChild(menu4, 51);

    //结束
    auto endItem = MenuItemImage::create(
        "StartScene/end.png",
        "StartScene/end.png",
        CC_CALLBACK_1(StartScene::endCallback, this));
    endItem->setPosition(Vec2(visibleSize.width / 2 + 240, visibleSize.height / 2 + 30));
    auto menu5 = Menu::create(endItem, NULL);
    menu5->setPosition(Vec2::ZERO);
    this->addChild(menu5, 51);

    //开始
    auto startItem = MenuItemImage::create(
        "StartScene/start.png",
        "StartScene/start.png",
        CC_CALLBACK_1(StartScene::startCallback, this));
    startItem->setPosition(Vec2(visibleSize.width / 2 + 200, visibleSize.height / 2 + 130));
    auto menu6 = Menu::create(startItem, NULL);
    menu6->setPosition(Vec2::ZERO);
    this->addChild(menu6, 51);

    return true;
}

void StartScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void StartScene::helpCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(StartHelpScene::createScene());
}

void StartScene::startCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(introductionScene::createScene());
}

void StartScene::endCallback(Ref* pSender)
{
    Director::getInstance()->end();
}