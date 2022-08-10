//第一张小纸条界面

#include "FirstTipScene.h"
#include "SecondPassScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

Scene* FirstTipScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = FirstTipScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool FirstTipScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("bgm/pass2bgm.mp3");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto nextItem = MenuItemImage::create(
        "FirstTips.png",
        "FirstTips.png",
        CC_CALLBACK_1(FirstTipScene::NextCallback, this));
    nextItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    nextItem->setScale(0.6);
    auto menu3 = Menu::create(nextItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);

    auto label = Label::createWithTTF(GBKToUTF8("ps: 俗话说“百川东到海”，所以水的源头就是岸啦！"),
        "fonts/tangyuan.ttf", 40);
    label->setPosition(Vec2(500,150));
    this->addChild(label, 1);

    //label->runAction(CCFadeIn::create(2));

    return true;
}
void FirstTipScene::NextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SecondPass::createScene());
}

