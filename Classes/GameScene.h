#pragma once
#include "cocos2d.h"
#include <vector>
#include <memory>
#include "PuzzlePartSprite.h"
#include "model/Gameboard.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    int boardSizeX;
    int boardSizeY;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    void drawPuzzleParts();
    std::vector<std::unique_ptr<PuzzlePartSprite>> parts;
    std::unique_ptr<Gameboard> board;
};
