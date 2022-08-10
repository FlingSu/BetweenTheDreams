//第二张小纸条界面
#include"SecondTipScene.h"
#include"SecondPassScene.h"

cocos2d::Scene* SecondTipScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = SecondTipScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool SecondTipScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto nextItem = MenuItemImage::create(
        "secondnext.png",
        "secondnext.png",
        CC_CALLBACK_1(SecondTipScene::NextCallback, this));
    nextItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    nextItem->setScale(0.6);
    auto menu3 = Menu::create(nextItem, NULL);
    menu3->setPosition(Vec2::ZERO);
    this->addChild(menu3, 1);

    auto label = Label::createWithTTF(GBKToUTF8("ps: 有勇气的捕梦者才能捡到小纸条哦！"),
        "fonts/tangyuan.ttf", 40);
    label->setPosition(Vec2(500, 150));
    this->addChild(label, 1);

    return true;
}

void SecondTipScene::NextCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(ThirdPassScene::createScene());
}
