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

    void border(char v);    //���Թ��ı�ȫ��Ϳ���ַ� v
    void fill(char v);    //���Թ��ڲ����Ϊ�ַ� v


    void dfsp(int x, int y);
    //˼·�����ѡ������·���߲��ݹ飬��·����ѡ����
    //����ת����·���˻���һ���ݹ�ֱ���ص���һ���ݹ麯��
public:
    MazeMap(int w, int h);
    ~MazeMap();
    inline bool checkBorder(int x, int y);    //�ж��Ƿ����Թ���

    void setWidth(int w);
    void setHeight(int h);

    void setSeed(unsigned int);
    unsigned int getSeed();

    void dfsMazeCreate();//����������������Թ�
    void printMap();    //����Թ�
};