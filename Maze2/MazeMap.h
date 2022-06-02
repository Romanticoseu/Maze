#pragma once
#include<iostream>
#include<ctime>
#include<windows.h>

//move
inline void gotoxy(int x, int y);

void setMappXY(char what, int x, int y);
char getMappXY(int x, int y);

class MazeMap
{
	int W, H;
    unsigned int theSeed;

    void border(char v);    //将迷宫四壁全部涂成字符 v
    void fill(char v);    //将迷宫内部填充为字符 v


    void dfsp(int x, int y);
    //思路：随机选择方向，有路则走并递归，无路则重选方向
    //四周转完无路则退回上一个递归直到回到第一个递归函数
public:
    MazeMap(int w, int h);
    ~MazeMap();
    inline bool checkBorder(int x, int y);    //判断是否在迷宫内

    void setWidth(int w);
    void setHeight(int h);

    void setSeed(unsigned int);
    unsigned int getSeed();

    void dfsMazeCreate();//深度优先搜索创建迷宫
    void printMap();    //输出迷宫
};