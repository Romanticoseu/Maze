#include"move.h"
using namespace std;

const char WALL = '#';
const char PATH = ' ';
const char PERSON = 'O';
const char TREASURE = '$';
const char TRAP = 'X';

bool move(int width, int height, int& stepNum)
{
    bool judge = true;
    int w = width;
    int h = height;
    int x = 0;
    int y = 1;

    gotoxy(x, y);//光标移动到入口
    putchar(PERSON);
    gotoxy(x, y);
    int ch = 0;
    while (1)
    {
        ch = _getch();
        if (ch == 224)
        {
            ch = _getch();
            putchar(PATH);//清除上次位置
        }
        switch (ch)
        {
        case 113://Q or q 中途退出
        case 81:
            judge = false;
            break;
        case 72://up
            if (y > 0 && getMappXY(x, y - 1) != WALL)
            {
                y--;
                stepNum++;
            }
            break;
        case 80://down
            if (y < 2 * h && getMappXY(x, y + 1) != WALL)
            {
                y++;
                stepNum++;
            }
            break;
        case 75://left
            if (x > 0 && getMappXY(x - 1, y) != WALL)
            {
                x--;
                stepNum++;
            }
            break;
        case 77://right
            if (x <= 2 * w && getMappXY(x + 1, y) != WALL)
            {
                x++;
                stepNum++;
            }
            break;
        default:
            break;
        }
        if (getMappXY(x, y) == TREASURE)
        {
            setMappXY(PATH, x, y);
            stepNum -= 50;
        }
        if (getMappXY(x, y) == TRAP)
        {
            setMappXY(PATH, x, y);
            stepNum += 50;
        }
        gotoxy(x, y);
        putchar(PERSON);
       
        //回到当前位置
        if (judge == false)
        {
            system("cls");
            cout << " Terminate this round!" << endl;
            break;
        }
        gotoxy(x, y);

        if (x == 2 * w && y == 2 * h - 1)
        {
            system("cls");
            cout << " You win!" << endl;
            break;
        }
    }
    return judge;
}
