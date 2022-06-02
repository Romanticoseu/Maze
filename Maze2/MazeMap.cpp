#include "MazeMap.h"
using namespace std;
const int MAX = 100;
char mapp[MAX][MAX];
char vis[MAX][MAX];
const int sleepTime = 10;

/* U R D L */
const int xx[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
const int yy[] = { -1, 0, 1, 0, -1, 1, -1, 1 };
const int x2[] = { 0, 2, 0, -2, -2, -2, 2, 2 };
const int y2[] = { -2, 0, 2, 0, -2, 2, -2, 2 };
const char WALL = '#';
const char PATH = ' ';
const char TREASURE = '$';
const char TRAP = 'X';

MazeMap::MazeMap(int w, int h)
    :W(2 * w), H(2 * h) 
{
    setSeed(static_cast<unsigned int>(time(NULL)));
}

MazeMap::~MazeMap()
{
}

void MazeMap::setSeed(unsigned int ran)
{
    theSeed = ran;
}

unsigned int MazeMap::getSeed()
{
    return theSeed;
}

void MazeMap::border(char v)
{
    for (int i = 0; i <= W; i++)
        mapp[0][i] = mapp[H][i] = v;
    for (int i = 2; i <= H; i++)
        mapp[i][0] = v;
    for (int i = 0; i <= H-2; i++)
        mapp[i][W] = v;
    mapp[H - 1][W] = PATH;
}

void MazeMap::fill(char v)
{
    for (int i = 1; i < H; i++)
        for (int j = 1; j < W; j++)
            mapp[i][j] = v;
}

void MazeMap::printMap()
{
    for (int i = 0; i <= H; i++) 
    {
        for (int j = 0; j <= W; j++) 
        {
            cout << mapp[i][j];
        }
        puts("");
    }
}

inline bool MazeMap::checkBorder(int x, int y)
{
    return x < W && x > 0 && y < H && y > 0;
}

void MazeMap::setWidth(int w)
{
    W = 2 * w;
}

void MazeMap::setHeight(int h)
{
    H = 2 * h;
}

void MazeMap::dfsp(int x, int y)
{
    int d, dic = 0;
    vis[y][x] = 1;

    /* go until no new direction */
    for (; dic != (1 << 4) - 1; dic |= 1 << d)
    {
        /* choose a random direction */
        do d = rand() % 4;
        while (dic & (1 << d));

        //2%�������ɶ���·��
        int poss = rand() % 100;
        if (poss < 2 
            && checkBorder(x + x2[d], y + y2[d]) //���߾�
            && vis[y + y2[d]][x + x2[d]])
        {
            /* connect CurrentPosition and NewPosition */
            mapp[y + yy[d]][x + xx[d]] = PATH;
            /* show progress */
            Sleep(sleepTime);
            //ˢ����ʾ
            gotoxy(x + xx[d], y + yy[d]);putchar(PATH);
        }

        if (checkBorder(x + x2[d], y + y2[d]) //���߾�
            && !vis[y + y2[d]][x + x2[d]]) //���Ŀ��λ���Ƿ�ɴ� Ѽ
        {
            /* connect CurrentPosition and NewPosition */
            mapp[y + yy[d]][x + xx[d]] = PATH;
            /* show progress */
            Sleep(sleepTime);
            //ˢ����ʾ
            gotoxy(x + xx[d], y + yy[d]);putchar(PATH);
            dfsp(x + x2[d], y + y2[d]);
        }
    }
}

void MazeMap::dfsMazeCreate()
{
    try
    {
        if (W > MAX || H > MAX)
            throw exception("Exceed MAX size!");
    }
    catch (const exception& str)
    {
        cerr << str.what() << endl;
        exit(0);
    }

    srand(theSeed);
    //memset��ʼ��mapp�ڴ�
    //ʵ��ԭ����ָ����� s ��ָ���ǰ n �ֽڵ��ڴ浥Ԫ��һ���������� c �滻
    memset(mapp, 0, sizeof(mapp));
    memset(vis, 0, sizeof(vis));

    //����ǽ
    border(WALL);
    fill(WALL);

    //&�������Ķ����������롱����
    //���ÿս��
    for (int i = 0; i <= H; i++)
        for (int j = 0; j <= W; j++)
            if (i & 1 && j & 1)
            {
                mapp[i][j] = PATH;
                if (2 > rand() % 1000 && rand() % 1000 > 0)
                    mapp[i][j] = TREASURE;
                else if (1 > rand() % 1000)
                    mapp[i][j] = TRAP;
            }
    //��һ�����
    gotoxy(0, 0); printMap();
    //��ʼ����·��
    dfsp(1, 1);
}

//move
inline void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setMappXY(char what, int x, int y)
{
    mapp[x][y] = what;
}

char getMappXY(int x, int y)
{
    return mapp[y][x];
}
