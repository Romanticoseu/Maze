#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include"MazeMap.h"
#include"move.h"
#include"ranking.h"
using namespace std;


int main()
{
    ranking game_ranking;
    bool counter = 0;
    system("color F0");
    while (true)
    {
        system("mode con: cols=120 lines=60");
        int step_number = 0;
        double time;
        int scores;
        int choose = 0;
        int w, h;
        int Seed = 0;
        MazeMap Map1(1, 1);
        system("cls");
        if (!counter)
        {
            cout << " Maze Game !!!" << endl;
            cout << " v-1.0.0" << endl;
            cout << " By ZeHua Cao,Xiaohui Luo,Jiajia Fan" << endl;
            system("pause");
            system("cls");
            counter++;
        }
        cout << " \t【 Menu 】\n" << endl;
        cout << " 【 1 】 ... Start the game" << endl;
        cout << " 【 2 】 ... Game tutorial" << endl;
        cout << " 【 3 】 ... Set color" << endl;
        cout << " 【 4 】 ... Production team" << endl;
        cout << " 【 5 】 ... Exit" << endl;
        cout << " >>> ";
        cin >> choose;
        switch (choose)
        {
        //start game
        case 1:
        {
            while (1)
            {
                system("cls");
                cout << " Choose the difficulty of your maze" << endl <<endl;
                cout << " Now the seed is:" << Map1.getSeed() << endl << endl;
                cout << " 【 0 】 ... Change your seed" << endl;
                cout << " 【 1 】 ... Easy\n 【 2 】 ... Normal\n 【 3 】 ... Difficult" << endl;
                cout << " 【 4 】 ... I will define it by myself!" << endl;
                cout << " >>> ";
                cin >> choose;
                switch (choose)
                {
                case 0:
                    system("cls");
                    cout << " Now the seed is:" << Map1.getSeed() << endl;
                    cout << " Please type in your new seed" << endl;
                    cout << " >>> ";
                    cin >> Seed;
                    Map1.setSeed(Seed);
                    cout << "\n Remember: Game has much unknown, and so is life." << endl;
                    Sleep(2000);
                    break;
                case 1:
                    w = 20, h = 10;
                    break;
                case 2:
                    w = 30, h = 15;
                    break;
                case 3:
                    w = 40, h = 20;
                    break;
                case 4:
                    while (1)
                    {
                        system("cls");
                        cout << " Define your own difficulty(w <= 50, h <= 24)" << endl;
                        cout << " Please enter the width" << endl;
                        cout << " >>> ";
                        cin >> w;
                        cout << " Please enter the height" << endl;
                        cout << " >>> ";
                        cin >> h;
                        if (w > 50 || h > 24 || w < 1 || h < 1)
                        {
                            cout << " Can not generate such a maze! Stupid!" << endl;
                            int choice;
                            cout << " 【 1 】 ... Re-enter parameters." << endl
                                 << " 【 2 】...Exit the game." << endl;
                            cout << " >>> ";
                            cin >> choice;
                            if (choice == 1)
                                continue;
                            if (choice == 2)
                                return 0;
                        }
                        system("cls");
                        break;
                    }
                }
                if (choose)
                    break;
            }
            break;
        }
           
        //game tutorial
        case 2:
        {
            system("cls");
            cout << " How to win the game?\n" << endl;
            cout << " You need to get you ('O') from the beginning to the end (by ↑,↓,←,→)." << endl;
            cout << " The '#' is the wall, you can not go through it." << endl;
            cout << " Find the shortest way!" << endl;
            cout << "\n P.S." << endl;
            cout << " There are treasure and traps in the Maze!" << endl;
            cout << " If you find the treasure '$', your number of steps will decrease 50" << endl;
            cout << " But if you meet the trap 'X', your number of steps will increase 50" << endl;
            cout << "\n Back to main menu" << endl;
            system("pause");
            continue;
        }
            
        //color
        case 3:
        {
            system("cls");
            cout << "0 = 黑色     8 = 灰色" << endl;
            cout << "1 = 蓝色     9 = 淡蓝色" << endl;
            cout << "2 = 绿色     A = 淡绿色" << endl;
            cout << "3 = 浅绿色   B = 淡浅绿色" << endl;
            cout << "4 = 红色     C = 淡红色" << endl;
            cout << "5 = 紫色     D = 淡紫色" << endl;
            cout << "6 = 黄色     E = 淡黄色" << endl;
            cout << "7 = 白色     F = 亮白色" << endl;
            cout << "Select the color of the backgroung:";
            string b_color = "F";
            cin >> b_color;
            cout << "Select the color of yourself:";
            string y_color = "0";
            cin >> y_color;
            string color;
            color = "color " + b_color + y_color;
            system(color.c_str());
            continue;
        }
            
        //team
        case 4:
        {
            system("cls");
            cout << " Game production team list." << endl;
            cout << " 1.Ji Yi." << endl
                << " 2.Sun Lifeng." << endl
                << " 3.Zhou Ziyi." << endl
                << " (Rank in alphabetical order)" << endl;
            cout << "\n Back to main menu" << endl;
            system("pause");
            continue;
        }
          
        //exit
        case 5:
        {
            return 0;
        }

        default:
        {
            continue;
        }
        }
        Map1.setWidth(w);
        Map1.setHeight(h);
        Map1.dfsMazeCreate();
        //重新输出使光标到迷宫最后
        gotoxy(0, 0); 
        Map1.printMap();
        cout << endl;
        bool trapTag = false;
        bool treaTag = false;
        for (int i = 0;i < 2 * w;i++)
            for (int j = 0; j < 2 * h; j++)
            {
                if (getMappXY(i, j) == '$' && treaTag == false) 
                {
                    cout << " 【 $ 】 -> Treasure" << endl;
                    treaTag = true;
                    break;
                }
                if (getMappXY(i, j) == 'X' && trapTag == false)
                {
                    cout << " 【 X 】 -> Trap" << endl;
                    trapTag = true;
                    break;
                }
            }
                
        cout << " Enter 【 Q 】 to exit" << endl;

        clock_t start_time, end_time;
        start_time = clock();
        //移动
        bool win = move(w, h, step_number);
        end_time = clock();
        time = (((double)(end_time)) - ((double)(start_time))) / CLOCKS_PER_SEC;
        scores = w * h - step_number - (int)time;
        if (win)
        {
            if(step_number >= 0)
                cout << " The number of your steps: " << step_number << endl;
            else
                cout << " Wonderful! The number of your steps is ZERO! (Because of treasure)" << endl;

            cout << " The time you used is: " << time << "s" << endl;
            cout << endl;
            if (scores >= 0)
                cout << " Your score is: " << scores << endl;
            else
            {
                cout << " Sorry, your score is ZERO..." << endl;
                scores = 0;
            }
            cout << endl;

            cout << " Want to submit your scores?" << endl;
            cout << " 【 1 】 ... Of course!\n 【 2 】 ... Please don\'t" << endl;
            cout << " >>> ";
            cin >> choose;
            cin.get();
            if (choose == 1)
            {
                string name = "f";
                cout << " Your name: " << endl;
                cout << " >>> ";
                getline(cin, name);
                game_ranking.update_ranking(make_pair(scores, name));
                game_ranking.print_ranking();
            }
        }
        int exit_choice;
        cout << " 【 1 】 ... New game?" << endl << " 【 2 】 ... Exit the game." << endl;
        cout << " >>> ";
        cin >> exit_choice;
        if (exit_choice == 1) 
            continue;
        if (exit_choice == 2) 
            break;
    }

    return 0;
}//end main

