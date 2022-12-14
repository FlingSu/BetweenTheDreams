# 梦境之间
    
    本作品是使用Cocos2d-x 3.17设计并开发的一款单机版叙事解谜游戏，名为《梦境之间》。
    玩家扮演主角“捕梦者”，先后经历三个光怪陆离的梦境：身处河流中心寻找正确的上岸方向、在怪物穷追不舍之下逃离至出口、参加高考并解答奇奇怪怪的试题。
    玩家在游玩过程中将面临选择，需要发动聪明才智才能想出答案，成功逃离梦境。

------

## 游戏截图

![image](https://user-images.githubusercontent.com/82498328/183918023-26469ca7-5df2-479b-9013-fb7dec2890c8.png)
![image](https://user-images.githubusercontent.com/82498328/183918207-260726f8-474b-4b7e-88fe-eaf0dc9fa7d3.png)
![image](https://user-images.githubusercontent.com/82498328/183918244-1bc574bf-d845-4b2a-b900-992bb8d85ab0.png)

![image](https://user-images.githubusercontent.com/82498328/183918262-a1060156-368d-49ad-a026-800bf32fd2be.png)
------

## 演示视频

[《梦境之间》演示视频_哔哩哔哩bilibili_演示](https://www.bilibili.com/video/BV1Jt4y1G7Xz/?vd_source=6b24955a154839f9ac0be79e833cf6dd)

------

## 编译

### 开发环境

- Cocos2d-x 3.17+
- Microsoft Visual Studio 2019+

### 创建项目

进入cocos2d-x-3.15.1\tools\cocos2d-console\bin 目录，按住shift+鼠标右键，在此处打开命令窗口。

使用 cocos new 命令创建新项目，命令格式如下： 

```
cocos new myProjectName -l cpp
```

使用 Between the Dreams' Code 文件夹中内容替换新项目中的Classes和Resources内容。
注意：在VS的工程文件夹中也需要替换成Classes中内容。

------

## 运行

本游戏使用Cocos2d-x引擎开发，由于该引擎不支持中文目录，请务必首先将游戏运行文件夹拷贝至电脑英文路径下（否则运行后无法加载配乐文件）！

### 游戏运行步骤

1、将Between the Dreams.zip解压移动至没有中文目录的地方。打开Between the Dreams文件夹，双击运行BetweentheDreams.exe即可开始游戏。

2、若运行时提示XXX.dll缺失，请到网上下载对应dll，将相应dll文件拷贝至Between the Dreams文件夹即可。
