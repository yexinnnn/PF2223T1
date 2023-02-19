// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT8L
// Names: LIM YE XIN| TER ZHENG BIN | LAI JIAN SENG
// IDs: 1211104730 | 1211103705 | 1211104601
// Emails: 1211104730@student.mmu.edu.my | 1211103705@student.mmu.edu.my | 1211104601@student.mmu.edu.my
// Phones: 010-3787368 | 019-7982299 | 012-3400237
// *********************************************************

#include "pf/helper.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iomanip> // for setw()
#include <fstream>
using namespace std;

class Zombie
{
public:
    int zombie_name;
    int zombie_life;
    int zombie_attack;
    int zombie_range;
    int zombie_row;
    int zombie_column;
    bool zombie_movement;

    Zombie(){};

    Zombie(int name, int life, int attack, int range, int row, int column)
    {
        zombie_name = name;
        zombie_life = life;
        zombie_attack = attack;
        zombie_range = range;
        zombie_row = row;
        zombie_column = column;
        zombie_movement = true;
    }
};

class Alien
{
public:
    int alien_life;
    int alien_attack;
    bool alien_movement;

    Alien()
    {
        alien_life = 100;
        alien_attack = 0;
        alien_movement = false;
    }

    void alien_attribute()
    {
        if (alien_movement == true)
        {
            cout << "-> ";
            cout << "Alien   :  Life = " << alien_life;
            cout << ", Attack : " << alien_attack << endl;
        }

        else
        {
            cout << "   ";
            cout << "Alien   :  Life = " << alien_life;
            cout << ", Attack : " << alien_attack << endl;
        }
    }
};

class Board : public Alien, public Zombie
{
private:
    vector<vector<char>> map_; // vector is made of "char"
    int newRows_, newColumns_, newZombieCounts_, newAlienrows_, newAliencolumns_;
    vector<char> control_items;
    vector<Zombie> zombie;
    int zombie_movement = 0;
    int noOfcontrol_items = 12;

public:
    Board(int board_rows, int board_columns, int numberOfzombie) // new variable will assign to private data
    {
        newRows_ = board_rows;
        newColumns_ = board_columns;
        newZombieCounts_ = numberOfzombie;
    }

    void zombie_attribute()
    {
        for (int i = 0; i < newZombieCounts_; ++i)
        {
            if (zombie_movement == i + 1)
            {
                cout << "-> ";
                cout << "Zombie" << i + 1;
                cout << " :  Life = " << zombie[i].zombie_life;
                cout << ", Attack :  " << zombie[i].zombie_attack;
                cout << "   , Range  : " << zombie[i].zombie_range;
                cout << ", Location = ";
                cout << "(" << zombie[i].zombie_row + 1 << ", " << newColumns_ - zombie[i].zombie_column << ")";
                cout << endl;
            }

            else
            {
                cout << "   ";
                cout << "Zombie" << i + 1;
                cout << " :  Life = " << zombie[i].zombie_life;
                cout << ", Attack : " << zombie[i].zombie_attack;
                cout << ", Range  : " << zombie[i].zombie_range;
                cout << ", Location = ";
                cout << "(" << zombie[i].zombie_row + 1 << ", " << newColumns_ - zombie[i].zombie_column << ")";
                cout << endl;
            }
        }
    }

    //------------Random display game objects------------//
    void random_items()
    {
        char control_items[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' '};
        int noOfcontrol_items = 12; // number of objects in the objects array
        srand(time(NULL));          // randomly display generate items

        //------------create dynamic 2D array using vector------------//
        map_.resize(newColumns_); // create empty rows
        cout << endl;
        for (int i = 0; i < newColumns_; ++i)
        {
            map_[i].resize(newRows_); // Resize each row
        }

        //------------put random objects into the vector array------------//
        for (int i = 0; i < newColumns_; ++i)
        {
            for (int j = 0; j < newRows_; ++j)
            {
                int objNo = rand() % noOfcontrol_items; // randomly generate object
                map_[i][j] = control_items[objNo];
                cout << map_[i][j];
            }
            cout << endl;
        }
    }

    void display()
    {
        cout.width(40); // to make "Alien Vs Zombie" to the center
        cout << "***Alien Vs Zombies***" << endl;

        //------------for each row------------//
        for (int i = 0; i < newColumns_; ++i)
        {
            cout.width(4);

            //------------display upper border of the row------------//
            cout << " ";
            for (int j = 0; j < newRows_; ++j) // newRows_ have how many, then this will display how many times
            {
                cout << "+-";
            }
            cout << "+" << endl; // end with a "+" sign symbol

            //------------display row number------------//
            cout << setw(2) << (newColumns_ - i); // set width to 2， columns number(5,4,3,2,1)

            //------------display cell content and border of each column------------//
            cout.width(3);
            for (int j = 0; j < newRows_; ++j)
            {
                cout << "|" << map_[i][j]; // for every item, will write a straight line first.Then only display content，[row][column]
            }
            cout << "|" << endl;
        }

        // ------------display lower border of the last row ------------//
        cout << " ";
        cout.width(5);
        for (int j = 0; j < newRows_; ++j)
        {
            cout << "+-"; // newRows_ have how many, then this will display how many times
        }
        cout << "+" << endl;

        //------------display column number------------//
        cout << " ";
        cout.width(4);
        for (int j = 0; j < newRows_; ++j) // j == 0, from 0 until 14
        {
            int digit = (j + 1) / 10; // because it use "ini" , so behind decimal are not counted
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
        }
        cout << endl;
        cout << " ";
        cout.width(4);
        for (int j = 0; j < newRows_; ++j)
        {
            cout << " " << (j + 1) % 10;
        }
        cout << endl
             << endl;

        alien_attribute();
        zombie_attribute();
    }

    //------------Check Object Displayed On GameBoard------------//

    // char getObject(int x,int y)const
    // {
    //     return map_[newColumns_ - y][x -1];
    // }

    // void test()
    // {
    //     int x,y;
    //     char obj;

    //     x = ((newRows_/2)+1); y = ((newColumns_ / 2)+1);
    //     obj = getObject(x,y);
    //     cout << "Object at column " << x << " and row " << y << " is ["
    //          << obj << "]" << endl;
    // }

    // void setObjects(int x, int y, char ch)
    // {
    //     map_[newColumns_ - y][x -1] = ch;
    //     // map_[-(newColumns_ - 5)][newRows_ - 1] = ch;
    // }

    void create_character()
    {
        //------------Create Alien------------//
        // int a_x = newRows_ / 2 + 1;
        // int a_y = newColumns_ / 2 + 1;
        // char ch1 = 'A';
        // setObjects(a_x,a_y,ch1);

        int a_x = newRows_ / 2 + 1;
        int a_y = newColumns_ / 2 + 1;
        cout << endl;
        cout << "Alien position" << endl;
        cout << "(" << a_x << ", " << a_y << ")" << endl;
        map_[newColumns_ / 2][newRows_ / 2] = 'A';
        cout << endl;

        //------------Create Zombie------------//
        srand(time(NULL));
        for (int i = 1, j = 49; i <= newZombieCounts_; ++i, ++j)
        {
            //------------random display zombie postion inside gameboard------------//
            int z_row = newRows_ / 2, z_column = newColumns_ / 2;
            while (z_row == newRows_ / 2 && z_column == newColumns_ / 2)
            {
                z_row = rand() % (newRows_);
                z_column = rand() % (newColumns_);
            }

            string name[] = {};
            int life[5] = {100, 120, 150, 140, 160};
            int attack[4] = {5, 10, 15, 20};
            int range[4] = {1, 2, 3, 4};

            zombie_name = i;
            // to_string(i);
            zombie_life = life[rand() % 5];
            zombie_attack = attack[rand() % 4];
            zombie_range = range[rand() % 5];

            //------------create a zombie vector with the variable name "zom" and pass the value into it------------//
            Zombie zom(zombie_name, zombie_life, zombie_attack, zombie_range, z_row, z_column);

            zombie.push_back(zom);           // push back is for the purpuse that
            map_[z_column][z_row] = char(j); // using char(49)=1 and assign it into the gamebroad
        }
    }

    //------------Check Alien's position------------//
    void alienposition()
    {
        for (int i = 0; i < newRows_; ++i)
        {
            for (int j = 0; j < newColumns_; ++j)
            {
                if (map_[j][i] == 'A')
                {
                    newAlienrows_ = i;    // row is from left to right or know as x
                    newAliencolumns_ = j; // columns is up to down or know as y
                    cout << "Alien position is at (" << newAlienrows_ + 1 << ", " << newColumns_ - newAliencolumns_ << ")" << endl;
                }
            }
        }
    }

    //-----------------------------------------Alien Movement-------------------------------------//

    //------------Alien Move Up------------//
    void up()
    {
        alienposition();
        int arrow_value = 0, rock_value = 0;

        for (int i = 1, j = 0; i <= newAliencolumns_; ++i, ++j)
        {
            //------------Check what is the item above Alien-----------//
            cout << endl;
            cout << "Item above Alien is (" << map_[newAliencolumns_ - i][newAlienrows_] << ")" << endl;

            //------------If Alien encounter '^' ------------------------//
            if (map_[newAliencolumns_ - i][newAlienrows_] == '^')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';

                returnback();
                display();
                up();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter 'v' ------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == 'v')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';

                returnback();
                display();
                down();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter '<' ------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == '<')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';

                returnback();
                display();
                left();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter '>' ------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == '>')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';

                returnback();
                display();
                right();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter pod ------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == 'p')
            {
                cout << "Alien finds a pod." << endl;         // set a biggest number so that they can compare with the other and replace it with the smaller one
                int nearestdistance = newRows_ * newColumns_; // to identify which one is the nearest zombie and replace it into zombie[x] where x is nearestzombie
                int nearestzombie = 0;
                for (int i = 0; i < newZombieCounts_; ++i)
                {
                    // ------------------------calculate the distenct between zombie and alien ------------------------//
                    int totaldist = abs(zombie[i].zombie_row - newAlienrows_) + abs(zombie[i].zombie_column - newAliencolumns_);
                    if (totaldist < nearestdistance)
                    {
                        nearestdistance = totaldist;
                        nearestzombie = i;
                    }
                }

                cout << "Zombie " << zombie[nearestzombie].zombie_name << " received a damage of 10." << endl; // print out the nearest zombie that received a damage checking by the loop "i".

                zombie[nearestzombie].zombie_life = zombie[nearestzombie].zombie_life - 10;
                if (zombie[nearestzombie].zombie_life <= 0)
                {
                    zombie[nearestzombie].zombie_life = 0;
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                }
                else
                {
                    cout << "Zombie" << zombie[nearestzombie].zombie_name << " is still alive." << endl;
                }

                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';
            }

            //------------If Alien encounter health care ------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's life is increased by 20." << endl;

                alien_life = alien_life + 20;

                if (alien_life > 100)
                {
                    alien_life = 100;
                }
                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';
            }

            //------------If Alien encounter a zombie------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == char(49) ||
                     map_[newAliencolumns_ - i][newAlienrows_] == char(50) ||
                     map_[newAliencolumns_ - i][newAlienrows_] == char(51) ||
                     map_[newAliencolumns_ - i][newAlienrows_] == char(52) ||
                     map_[newAliencolumns_ - i][newAlienrows_] == char(53))
            {
                int zombiefight = int(map_[newAliencolumns_ - i][newAlienrows_] - 49);
                cout << "Alien hit the Zombie " << zombie[zombiefight].zombie_name << endl;
                zombie[zombiefight].zombie_life = zombie[zombiefight].zombie_life - alien_attack;

                if (zombie[zombiefight].zombie_life <= 0)
                {
                    zombie[zombiefight].zombie_life = 0;
                    map_[newAliencolumns_ - i][newAlienrows_] = char(zombiefight + 49);
                    cout << zombie[zombiefight].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                }
                else
                {
                    cout << "Zombie " << zombie[zombiefight].zombie_name << " is still alive." << endl;

                    rock_value = 1;
                    break;
                    returnback();
                    display();
                }
            }
            //------------If Alien encounter rock ------------------------//
            else if (map_[newAliencolumns_ - i][newAlienrows_] == 'r')
            {
                char control_items[] = {'^', 'v', '<', '>', 'h', 'p', ' '};
                int noOfcontrol_items = 7;
                string itemdisplay;

                int objNum = rand() % 7;
                map_[newAliencolumns_ - i][newAlienrows_] = control_items[objNum];

                if (objNum == 0)
                {
                    itemdisplay = "^";
                }
                else if (objNum == 1)
                {
                    itemdisplay = "v";
                }
                else if (objNum == 2)
                {
                    itemdisplay = "<";
                }
                else if (objNum == 3)
                {
                    itemdisplay = ">";
                }
                else if (objNum == 4)
                {
                    itemdisplay = "h";
                }
                else if (objNum == 5)
                {
                    itemdisplay = "p";
                }
                else if (objNum == 6)
                {
                    itemdisplay = " ";
                }

                cout << "Alien stumble upon a rock and stopped." << endl;
                cout << "Alien discovered a " << itemdisplay << " beneath the rock." << endl;
                cout << endl;
                returnback();
                display();

                rock_value = 1;
                break;
            }
            //------------If Alien encounter a space ------------------------//
            else
            {
                map_[newAliencolumns_ - i][newAlienrows_] = 'A';
                map_[newAliencolumns_ - j][newAlienrows_] = '.';
            }
            cout << endl;
            returnback();
            display();
        }

        //------------If Alien encounter border ------------------------//
        if (rock_value == 0 && arrow_value == 0)
        {
            cout << endl;
            cout << "Alien hits a border and stop moving." << endl;
            cout << endl;
            returnback();
            display();
        }
    }

    //------------Alien Move down------------//
    void down()
    {
        alienposition();
        int arrow_value = 0, rock_value = 0;

        for (int i = 1, j = 0; i <= newColumns_ - newAliencolumns_ - 1; ++i, ++j)
        {
            //------------Check what is the item above Alien-----------//
            cout << endl;
            cout << "Item below Alien is (" << map_[newAliencolumns_ + i][newAlienrows_] << ")" << endl;

            //------------If Alien encounter '^' ------------------------//
            if (map_[newAliencolumns_ + i][newAlienrows_] == '^')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';
                returnback();
                display();
                up();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter 'v' ------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == 'v')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';

                returnback();
                display();
                down();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter '<' ------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == '<')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';

                returnback();
                display();
                left();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter '>' ------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == '>')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';

                returnback();
                display();
                right();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter pod ------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == 'p')
            {
                cout << "Alien finds a pod." << endl; // set a biggest number so that they can compare with the other and replace it with the smaller one
                int nearestdistance = newRows_ * newColumns_;
                int nearestzombie = 0; // to identify which one is the nearest zombie and replace it into zombie[x] where x is nearestzombie
                for (int i = 0; i < newZombieCounts_; ++i)
                {
                    // ------------------------Calculate the distenct between zombie and alien ------------------------//
                    int totaldist = abs(zombie[i].zombie_row - newAlienrows_) + abs(zombie[i].zombie_column - newAliencolumns_);
                    if (totaldist < nearestdistance)
                    {
                        nearestdistance = totaldist;
                        nearestzombie = i;
                    }
                }

                cout << "Zombie " << zombie[nearestzombie].zombie_name << " received a damage of 10." << endl; // print out the nearest zombie that received a damage checking by the loop "i".

                zombie[nearestzombie].zombie_life = zombie[nearestzombie].zombie_life - 10; // making a condition to make sure that zombie that been atteck was dead or not
                if (zombie[nearestzombie].zombie_life <= 0)
                {
                    zombie[nearestzombie].zombie_life = 0;
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                }
                else
                {
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is still alive." << endl;
                }
                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';
            }

            //------------If Alien encounter health care ------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's life is increased by 20." << endl;
                alien_life = alien_life + 20;
                if (alien_life > 100)
                {
                    alien_life = 100;
                }
                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';
            }

            //------------If Alien encounter a zombie------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == char(49) ||
                     map_[newAliencolumns_ + i][newAlienrows_] == char(50) ||
                     map_[newAliencolumns_ + i][newAlienrows_] == char(51) ||
                     map_[newAliencolumns_ + i][newAlienrows_] == char(52) ||
                     map_[newAliencolumns_ + i][newAlienrows_] == char(53))
            {
                //------------zombiefight is to find which zombie alien facing to and atteck it--------------------//
                int zombiefight = int(map_[newAliencolumns_ + i][newAlienrows_] - 49);
                cout << "Alien hit the Zombie " << zombie[zombiefight].zombie_name << endl;
                zombie[zombiefight].zombie_life = zombie[zombiefight].zombie_life - alien_attack;

                if (zombie[zombiefight].zombie_life <= 0)
                {
                    zombie[zombiefight].zombie_life = 0;
                    map_[newAliencolumns_ + i][newAlienrows_] = char(zombiefight + 49);
                    cout << zombie[zombiefight].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                }
                else
                {
                    cout << "Zombie " << zombie[zombiefight].zombie_name << " is still alive." << endl;

                    rock_value = 1;
                    break;
                    returnback();
                    display();
                }
            }

            //------------If Alien encounter rock ------------------------//
            else if (map_[newAliencolumns_ + i][newAlienrows_] == 'r')
            {
                char control_items[] = {'^', 'v', '<', '>', 'h', 'p', ' '};
                int noOfcontrol_items = 7;
                string itemdisplay;

                int objNum = rand() % 7;
                map_[newAliencolumns_ + i][newAlienrows_] = control_items[objNum];

                if (objNum == 0)
                {
                    itemdisplay = "^";
                }
                else if (objNum == 1)
                {
                    itemdisplay = "v";
                }
                else if (objNum == 2)
                {
                    itemdisplay = "<";
                }
                else if (objNum == 3)
                {
                    itemdisplay = ">";
                }
                else if (objNum == 4)
                {
                    itemdisplay = "h";
                }
                else if (objNum == 5)
                {
                    itemdisplay = "p";
                }
                else if (objNum == 6)
                {
                    itemdisplay = " ";
                }

                cout << "Alien stumble upon a rock and stopped." << endl;
                cout << "Alien discovered a " << itemdisplay << " beneath the rock." << endl;
                cout << endl;
                returnback();
                display();

                rock_value = 1;
                break;
            }
            //------------If Alien encounter a space ------------------------//
            else
            {
                map_[newAliencolumns_ + i][newAlienrows_] = 'A';
                map_[newAliencolumns_ + j][newAlienrows_] = '.';
            }
            cout << endl;
            returnback();
            display();
        }
        //------------If Alien encounter border ------------------------//
        if (arrow_value == 0 && rock_value == 0)
        {
            cout << endl;
            cout << "Alien hits a border and moving stopped." << endl;
            cout << endl;
            returnback();
            display();
        }
    }

    //------------Alien Move left------------//
    void left()
    {
        alienposition();
        int arrow_value = 0, rock_value = 0;
        for (int i = 1, j = 0; i <= newAlienrows_ + 1; ++i, ++j)
        {
            //------------Check what is the item above Alien-----------//
            cout << endl;
            cout << "Item on the left side of Alien is (" << map_[newAliencolumns_][newAlienrows_ - i] << ")" << endl;

            //------------If Alien encounter '^' ------------------------//
            if (map_[newAliencolumns_][newAlienrows_ - i] == '^')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';
                returnback();
                display();
                up();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter 'v' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == 'v')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';

                returnback();
                display();
                down();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter '<' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == '<')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';

                returnback();
                display();
                left();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter '>' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == '>')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';

                returnback();
                display();
                right();
                arrow_value = 1;
                break;
            }

            //------------If Alien encounter 'pod' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == 'p')
            {
                cout << "Alien finds a pod." << endl;         // set a biggest number so that they can compare with the other and replace it with the smaller one
                int nearestdistance = newRows_ * newColumns_; // to identify which one is the nearest zombie and replace it into zombie[x] where x is nearestzombie
                int nearestzombie = 0;
                for (int i = 0; i < newZombieCounts_; ++i)
                {
                    //------------------------Calculate the distenct between zombie and alien------------------------//
                    int totaldist = abs(zombie[i].zombie_row - newAlienrows_) + abs(zombie[i].zombie_column - newAliencolumns_);
                    if (totaldist < nearestdistance)
                    {
                        nearestdistance = totaldist;
                        nearestzombie = i;
                    }
                }
                cout << "Zombie " << zombie[nearestzombie].zombie_name << " received a damage of 10." << endl; // print out the nearest zombie that received a damage checking by the loop "i".
                zombie[nearestzombie].zombie_life = zombie[nearestzombie].zombie_life - 10;
                if (zombie[nearestzombie].zombie_life <= 0)
                {
                    zombie[nearestzombie].zombie_life = 0;
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                }
                else
                {
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is still alive." << endl;
                }

                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';
            }

            //------------If Alien encounter health care ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's life is increased by 20." << endl;
                alien_life = alien_life + 20;
                if (alien_life > 100)
                {
                    alien_life = 100;
                }
                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';
            }

            //------------If Alien encounter a zombie------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == char(49) ||
                     map_[newAliencolumns_][newAlienrows_ - i] == char(50) ||
                     map_[newAliencolumns_][newAlienrows_ - i] == char(51) ||
                     map_[newAliencolumns_][newAlienrows_ - i] == char(52) ||
                     map_[newAliencolumns_][newAlienrows_ - i] == char(53))
            {
                //------------zombiefight is to find which zombie alien facing to and atteck it--------------------//
                int zombiefight = int(map_[newAliencolumns_][newAlienrows_ - i] - 49);
                cout << "Alien hit the Zombie " << zombie[zombiefight].zombie_name << endl;
                zombie[zombiefight].zombie_life = zombie[zombiefight].zombie_life - alien_attack;

                if (zombie[zombiefight].zombie_life <= 0)
                {
                    zombie[zombiefight].zombie_life = 0;
                    map_[newAliencolumns_][newAlienrows_ - i] = char(zombiefight + 49);
                    cout << zombie[zombiefight].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                    break;
                }
                else
                {
                    cout << "Zombie " << zombie[zombiefight].zombie_name << " is still alive." << endl;

                    rock_value = 1;
                    break;
                    returnback();
                    display();
                }
            }

            //------------If Alien encounter rock ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ - i] == 'r')
            {
                char control_items[] = {'^', 'v', '<', '>', 'h', 'p', ' '};
                int noOfcontrol_items = 7;
                string itemdisplay;

                int objNum = rand() % 7;
                map_[newAliencolumns_][newAlienrows_ - i] = control_items[objNum];

                if (objNum == 0)
                {
                    itemdisplay = "^";
                }
                else if (objNum == 1)
                {
                    itemdisplay = "v";
                }
                else if (objNum == 2)
                {
                    itemdisplay = "<";
                }
                else if (objNum == 3)
                {
                    itemdisplay = ">";
                }
                else if (objNum == 4)
                {
                    itemdisplay = "h";
                }
                else if (objNum == 5)
                {
                    itemdisplay = "p";
                }
                else if (objNum == 6)
                {
                    itemdisplay = " ";
                }

                cout << "Alien stumble upon a rock and stopped." << endl;
                cout << "Alien discovered a " << itemdisplay << " beneath the rock." << endl;
                cout << endl;
                returnback();
                display();

                rock_value = 1;
                break;
            }

            //------------If Alien encounter a space ------------------------//
            else
            {
                map_[newAliencolumns_][newAlienrows_ - i] = 'A';
                map_[newAliencolumns_][newAlienrows_ - j] = '.';
            }
            cout << endl;
            returnback();
            display();
        }

        //------------If Alien encounter border ------------------------//
        if (arrow_value == 0 && rock_value == 0)
        {
            cout << endl;
            cout << "Alien hits a border and moving stopped." << endl;
            cout << endl;
            returnback();
            display();
        }
    }

    //------------Alien Move Right------------//
    void right()
    {
        alienposition();
        int arrow_value = 0, rock_value = 0;

        for (int i = 1, j = 0; i <= newRows_ - newAlienrows_ - 1; ++i, ++j)
        {
            //------------Check what is the item above Alien-----------//
            cout << endl;
            cout << "Item on the right side of Alien is (" << map_[newAliencolumns_][newAlienrows_ + i] << ")" << endl;

            //------------If Alien encounter '^' ------------------------//
            if (map_[newAliencolumns_][newAlienrows_ + i] == '^')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';
                returnback();
                display();
                up();
                arrow_value = 1;
                break;
            }
            //------------If Alien encounter 'v' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ + i] == 'v')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';

                returnback();
                display();
                down();
                arrow_value = 1;
                break;
            }
            //------------If Alien encounter '<' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ + i] == '<')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';

                returnback();
                display();
                left();
                arrow_value = 1;
                break;
            }
            //------------If Alien encounter '>' ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ + i] == '>')
            {
                cout << "Alien finds an arrow." << endl;
                cout << "Alien's attack increased by 20." << endl;
                cout << endl;

                alien_attack = alien_attack + 20;

                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';

                returnback();
                display();
                right();
                arrow_value = 1;
                break;
            }
            //------------If Alien encounter pod ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ + i] == 'p')
            {
                cout << "Alien finds a pod." << endl;         // set a biggest number so that they can compare with the other and replace it with the smaller one
                int nearestdistance = newRows_ * newColumns_; // to identify which one is the nearest zombie and replace it into zombie[x] where x is nearestzombie
                int nearestzombie = 0;
                for (int i = 0; i < newZombieCounts_; ++i)
                {
                    //------------------------Calculate the distenct between zombie and alien------------------------//
                    int totaldist = abs(zombie[i].zombie_row - newAlienrows_) + abs(zombie[i].zombie_column - newAliencolumns_);
                    if (totaldist < nearestdistance)
                    {
                        nearestdistance = totaldist;
                        nearestzombie = i;
                    }
                }

                cout << "Zombie " << zombie[nearestzombie].zombie_name << " received a damage of 10." << endl; // print out the nearest zombie that received a damage checking by the loop "i".
                zombie[nearestzombie].zombie_life = zombie[nearestzombie].zombie_life - 10;

                if (zombie[nearestzombie].zombie_life <= 0)
                {
                    zombie[nearestzombie].zombie_life = 0;
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                }
                else
                {
                    cout << "Zombie " << zombie[nearestzombie].zombie_name << " is still alive." << endl;
                }

                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';
            }
            //------------If Alien encounter health care ------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ + i] == 'h')
            {
                cout << "Alien finds a health pack." << endl;
                cout << "Alien's life is increased by 20." << endl;
                alien_life = alien_life + 20;
                if (alien_life > 100)
                {
                    alien_life = 100;
                }
                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';
            }

            //------------If Alien encounter a zombie------------------------//
            else if (map_[newAliencolumns_][newAlienrows_ + i] == char(49) ||
                     map_[newAliencolumns_][newAlienrows_ + i] == char(50) ||
                     map_[newAliencolumns_][newAlienrows_ + i] == char(51) ||
                     map_[newAliencolumns_][newAlienrows_ + i] == char(52) ||
                     map_[newAliencolumns_][newAlienrows_ + i] == char(53))
            {
                //-----------------zombiefight is to find which zombie alien facing to and atteck it--------------------//
                int zombiefight = int(map_[newAliencolumns_][newAlienrows_ + i] - 49);
                cout << "Alien hit the Zombie " << zombie[zombiefight].zombie_name << endl;
                zombie[zombiefight].zombie_life = zombie[zombiefight].zombie_life - alien_attack;

                if (zombie[zombiefight].zombie_life <= 0)
                {
                    zombie[zombiefight].zombie_life = 0;
                    map_[newAliencolumns_][newAlienrows_ + i] = char(zombiefight + 49);
                    cout << zombie[zombiefight].zombie_name << " is defeated." << endl;
                    cout << endl;
                    cout << "All zombie has been defeated." << endl;
                    repeat_game();
                    break;
                }
                else
                {
                    cout << "Zombie " << zombie[zombiefight].zombie_name << " is still alive." << endl;

                    rock_value = 1;
                    break;
                    returnback();
                    display();
                }
            }
            //------------If Alien encounter rock ------------------------//
            if (map_[newAliencolumns_][newAlienrows_ + i] == 'r')
            {
                char control_items[] = {'^', 'v', '<', '>', 'h', 'p', ' '};
                int noOfcontrol_items = 7;
                string itemdisplay;

                int objNum = rand() % 7;
                map_[newAliencolumns_][newAlienrows_ + i] = control_items[objNum];

                if (objNum == 0)
                {
                    itemdisplay = "^";
                }
                else if (objNum == 1)
                {
                    itemdisplay = "v";
                }
                else if (objNum == 2)
                {
                    itemdisplay = "<";
                }
                else if (objNum == 3)
                {
                    itemdisplay = ">";
                }
                else if (objNum == 4)
                {
                    itemdisplay = "h";
                }
                else if (objNum == 5)
                {
                    itemdisplay = "p";
                }
                else if (objNum == 6)
                {
                    itemdisplay = " ";
                }
                cout << "Alien stumble upon a rock and stopped." << endl;
                cout << "Alien discovered a " << itemdisplay << " beneath the rock." << endl;
                cout << endl;
                returnback();
                display();

                rock_value = 1;

                break;
            }
            //------------If Alien encounter a space ------------------------//
            else
            {
                map_[newAliencolumns_][newAlienrows_ + i] = 'A';
                map_[newAliencolumns_][newAlienrows_ + j] = '.';
            }
            cout << endl;
            returnback();
            display();
        }
        //------------If Alien encounter border ------------------------//
        if (arrow_value == 0 && rock_value == 0)
        {
            cout << endl;
            cout << "Alien hits a border and moving stopped." << endl;
            cout << endl;
            returnback();
            display();
        }
    }

    //------------Change gameboard's arrow ------------------------//
    void arrow()
    {
        int direction_row;
        int direction_column;
        string direction;

        cout << endl;
        cout << "Enter row      : ";
        cin >> direction_column;
        cout << "Enter column   : ";
        cin >> direction_row;
        cout << "Enter direction [up/down/left/right]: ";
        cin >> direction;
        cout << endl;

        // ---------- Change arrow '^' ---------- //
        if (map_[-(direction_column - newColumns_)][(direction_row - 1)] == '^')
        {
            if (direction == "down")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = 'v';
                cout << "Arrow '^' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "left")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '<';
                cout << "Arrow '^' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "right")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '>';
                cout << "Arrow '^' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else
            {
                cout << "Invalid direction." << endl;
                arrow();
            }

            returnback();
            display();
            commands();
        }

        // ---------- Change arrow 'v' ---------- //
        if (map_[-(direction_column - newColumns_)][(direction_row - 1)] == 'v')
        {
            if (direction == "up")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '^';
                cout << "Arrow 'v' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "left")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '<';
                cout << "Arrow 'v' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "right")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '>';
                cout << "Arrow 'v' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else
            {
                cout << "Invalid direction." << endl;
                arrow();
            }

            returnback();
            display();
            commands();
        }

        // ---------- Change arrow '<' ---------- //
        if (map_[-(direction_column - newColumns_)][(direction_row - 1)] == '<')
        {
            if (direction == "up")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '^';
                cout << "Arrow '<' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "down")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = 'v';
                cout << "Arrow '<' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "right")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '>';
                cout << "Arrow '<' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else
            {
                cout << "Invalid direction." << endl;
                arrow();
            }

            returnback();
            display();
            commands();
        }

        // ---------- Change arrow '>' ---------- //
        if (map_[-(direction_column - newColumns_)][(direction_row - 1)] == '>')
        {
            if (direction == "up")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '^';
                cout << "Arrow '>' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "down")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = 'v';
                cout << "Arrow '>' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else if (direction == "left")
            {
                map_[-(direction_column - newColumns_)][(direction_row - 1)] = '<';
                cout << "Arrow '>' is switched to '" << map_[-(direction_column - newColumns_)][(direction_row - 1)] << "'" << endl;
            }
            else
            {
                cout << "Invalid direction." << endl;
                arrow();
            }

            returnback();
            display();
            commands();
        }

        else
        {
            cout << "Invalid input, please enter again";
            arrow();
        }
    }

    //-------------------- Zombie Moves -----------------------//
    void zombie_move()
    {
        srand(time(NULL));
        for (int i = 0; i < newZombieCounts_; ++i)
        {
            //--------------Display which zombie turn now--------------//
            zombie_movement = zombie_movement + 1;
            if (zombie[i].zombie_movement == true)
            {
                display();
                cout << endl;
                cout << "Zombie " << i + 1 << " turns." << endl;
                cout << endl;
                returnback();

                // ---------- Zombie Moves ---------- //
                int zom_row = zombie[i].zombie_row;
                int zom_column = zombie[i].zombie_column;

                //------------To check item above zombie [up down left right] ---------- //
                // char up = map_[zom_column - 1][zom_row];
                // char down = map_[zom_column + 1][zom_row];
                // char left = map_[zom_column][zom_row - 1];
                // char right = map_[zom_column][zom_row + 1];
                char up;
                char down;
                char left;
                char right;

                //---------------------------------------------Zombie faces problem in 4 direction---------------------------------------------------- //
                if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                    (down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9') &&
                    (left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9') &&
                    (right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char down = map_[zom_column + 1][zom_row];
                    char left = map_[zom_column][zom_row - 1];
                    char right = map_[zom_column][zom_row + 1];
                    cout << "Zombie " << zombie[i].zombie_name << " unable to move." << endl;
                }

                //---------------------------------------------Zombie faces problem in 3 direction--------------------------------------------------- //
                // ---------- Zombie only able to move to the up ---------- //
                else if ((down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9') &&
                         (left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9') &&
                         (right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char down = map_[zom_column + 1][zom_row];
                    char left = map_[zom_column][zom_row - 1];
                    char right = map_[zom_column][zom_row + 1];

                    zombie[i].zombie_column -= 1;
                    map_[zom_column - 1][zom_row] = char(i + 49);
                    map_[zom_column][zom_row] = ' ';
                    cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                }
                // ---------- Zombie only able to move to the up ---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                         (left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9') &&
                         (right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char left = map_[zom_column][zom_row - 1];
                    char right = map_[zom_column][zom_row + 1];

                    zombie[i].zombie_column += 1;
                    map_[zom_column + 1][zom_row] = char(i + 49);
                    map_[zom_column][zom_row] = ' ';
                    cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                }
                // ---------- Zombie only able to move to the left ---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                         (down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9') &&
                         (right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char down = map_[zom_column + 1][zom_row];
                    char right = map_[zom_column][zom_row + 1];

                    zombie[i].zombie_row -= 1;
                    map_[zom_column][zom_row - 1] = char(i + 49);
                    map_[zom_column][zom_row] = ' ';
                    cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                }
                // ---------- Zombie only able to move to the right ---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                         (down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9') &&
                         (left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char down = map_[zom_column + 1][zom_row];
                    char left = map_[zom_column][zom_row - 1];

                    zombie[i].zombie_row += 1;
                    map_[zom_column][zom_row + 1] = char(i + 49);
                    map_[zom_column][zom_row] = ' ';
                    cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                }
                //---------------------------------------------Zombie faces problem in 2 direction-------------------------------------------------- //
                // ---------- Zombie only able to move to the up & down ---------- //
                else if ((left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9') &&
                         (right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char left = map_[zom_column][zom_row - 1];
                    char right = map_[zom_column][zom_row + 1];

                    int move = rand() % 2;
                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                }
                // ---------- Zombie only able to move to the left & right ---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                         (down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char down = map_[zom_column + 1][zom_row];

                    int move = rand() % 2;
                    if (move == 0)
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }

                // ---------- Zombie only able to move to the up & right ---------- //
                else if ((left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9') &&
                         (down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9'))
                {
                    char left = map_[zom_column][zom_row - 1];
                    char down = map_[zom_column + 1][zom_row];

                    int move = rand() % 2;
                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }
                // ---------- Zombie only able to move to the up & left ---------- //
                else if ((right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9') &&
                         (down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9'))
                {
                    char down = map_[zom_column + 1][zom_row];
                    char right = map_[zom_column][zom_row + 1];

                    int move = rand() % 2;
                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                }
                // ---------- Zombie only able to move to the down & right ---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                         (left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char left = map_[zom_column][zom_row - 1];

                    int move = rand() % 2;
                    if (move == 0)
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }
                // ---------- Zombie only able to move to the down & left ---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9') &&
                         (right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];
                    char right = map_[zom_column][zom_row + 1];

                    int move = rand() % 2;
                    if (move == 0)
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                }
                //---------------------------------------------Zombie faces problem in 1 direction--------------------------------------------------- //
                // ---------- Zombie only able to move to the up,down & left---------- //
                else if ((right == 'A' || right == '1' || right == '2' || right == '3' || right == '4' || right == '5' || right == '6' || right == '7' || right == '8' || right == '9'))
                {
                    char right = map_[zom_column][zom_row + 1];

                    int move = rand() % 3;
                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else if (move == 1)
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                }

                // ---------- Zombie only able to move to the up,down & right---------- //
                else if ((left == 'A' || left == '1' || left == '2' || left == '3' || left == '4' || left == '5' || left == '6' || left == '7' || left == '8' || left == '9'))
                {
                    char left = map_[zom_column][zom_row - 1];

                    int move = rand() % 3;
                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else if (move == 1)
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }
                // ---------- Zombie only able to move to the up,left & right---------- //
                else if ((down == 'A' || down == '1' || down == '2' || down == '3' || down == '4' || down == '5' || down == '6' || down == '7' || down == '8' || down == '9'))
                {
                    char down = map_[zom_column + 1][zom_row];

                    int move = rand() % 3;
                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else if (move == 1)
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }
                // ---------- Zombie only able to move to the down,left & right---------- //
                else if ((up == 'A' || up == '1' || up == '2' || up == '3' || up == '4' || up == '5' || up == '6' || up == '7' || up == '8' || up == '9'))
                {
                    char up = map_[zom_column - 1][zom_row];

                    int move = rand() % 3;
                    if (move == 0)
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                    else if (move == 1)
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }
                //---------------------------------------------Zombie faces no problem in all direction--------------------------------------------------- //
                else
                {
                    int move = rand() % 4;

                    if (move == 0)
                    {
                        zombie[i].zombie_column -= 1;
                        map_[zom_column - 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the up." << endl;
                    }
                    else if (move == 1)
                    {
                        zombie[i].zombie_column += 1;
                        map_[zom_column + 1][zom_row] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the down." << endl;
                    }
                    else if (move == 2)
                    {
                        zombie[i].zombie_row -= 1;
                        map_[zom_column][zom_row - 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the left." << endl;
                    }
                    else
                    {
                        zombie[i].zombie_row += 1;
                        map_[zom_column][zom_row + 1] = char(i + 49);
                        map_[zom_column][zom_row] = ' ';
                        cout << "Zombie " << zombie[i].zombie_name << " move to the right." << endl;
                    }
                }

                //--------------------------Zombie attack alien in every turns----------------------------------------------------------//
                //-------------------Calculate zombie & alien distance in order to attack-----------------//
                int total_distance = abs(zombie[i].zombie_row - newAlienrows_) + abs(zombie[i].zombie_column - newAliencolumns_);
                if (total_distance <= zombie[i].zombie_range)
                {
                    cout << "Zombie " << zombie[i].zombie_name << " attacks Alien." << endl;
                    cout << "Alien receives a damage of " << zombie[i].zombie_attack << "." << endl;
                    alien_life = alien_life - zombie[i].zombie_attack;

                    if (alien_life <= 0)
                    {
                        alien_life = 0;

                        returnback();
                        display();

                        cout << endl;
                        cout << "Alien has been defeated." << endl;
                        cout << "Game Over." << endl;
                        quit();
                    }
                    else
                    {
                        cout << endl;
                        returnback();
                        display();

                        cout << endl;
                        cout << "Alien is still alive." << endl;
                        cout << endl;
                    }
                }
                else
                {
                    cout << "Zombie " << zombie[i].zombie_name << " is unable to attack Alien." << endl;
                    cout << "Alien is too far." << endl;
                }
                cout << endl;
                returnback();
            }
        }

        //-----------------------------Alien turn---------------------//
        zombie_movement = 0;
        alien_movement = true;
        display();
        commands();
    }

    //------------Trail reset after Alien's move------------//
    void trail_reset()
    {
        char control_items[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' '};
        int noOfcontrol_items = 12;
        cout << endl;
        cout << "Alien's turn ends. The trail is reset." << endl;
        returnback();
        alien_attack = 0;
        alien_movement = false;

        for (int i = 0; i < newColumns_; ++i)
        {
            for (int j = 0; j < newRows_; ++j)
            {
                if (map_[i][j] == '.')
                {
                    int objNo = rand() % noOfcontrol_items;
                    map_[i][j] = control_items[objNo];
                }
            }
        }
    }

    void save()
    {
        {
            string filename;
            bool saved;
            alienposition();
            display();

            string file;
            cout << "Enter the file name you want to save the game. (without .txt) -> ";
            cin >> file;
            ofstream myfile;
            filename = file + ".txt";
            myfile.open(filename, ios::out);
            if (myfile.is_open())

            {
                // write game settings
                myfile << "Board Rows : " << newRows_ << ", "
                       << "Board Columns: " << newColumns_ << ", "
                       << "Amount of Zombie: " << newZombieCounts_ << " " << endl;

                // write game board


                for (int i = 0; i < newColumns_; ++i)
                {
                    for (int j = 0; j < newRows_; ++j)
                    {
                        myfile << map_[i][j];
                    }
                    myfile << endl;
                }

                // write alien status
                myfile << "Alien : "
                       << " Life = " << alien_life << ", "
                       << "Attack : " << alien_attack << ", "
                       << "Location = " << newAlienrows_ + 1 << ", " << newColumns_ - newAliencolumns_ << " " << endl;

                // write zombie status
                for (int i = 0; i <= newZombieCounts_; i++)
                {
                    myfile << "Zombie " << zombie[i].zombie_name << ": "
                           << " Life = " << zombie[i].zombie_life << ", "
                           << "Attack : " << zombie[i].zombie_attack << ", "
                           << "Range :" << zombie[i].zombie_range << ", "
                           << "Location = " << zombie[i].zombie_row + 1 << ", " << newColumns_ - zombie[i].zombie_column << endl;
                }
                saved = true;
            }
            else
            {
                saved = false;
            }

            myfile.close();
        }
    }

    void load()
    {

        string filename;
        bool saved;
        string file;
        cout << "Enter the file name you want to load the game. (without .txt)" << endl;
        cout << "-> ";
        cin >> file;

        fstream myfile;
        filename = file + ".txt";

        string line;
        myfile.open(filename, ios::in);
        

        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                cout << line << endl;
            }
            commands();
        }
    }
    // repeat game after zombie die or alien die
    void repeat_game()
    {
        cout << "Game Over !!!" << endl;
        cout << "Did you want to play again (Y/N)?" << endl;
        cout << "input ->";
        string userinput;
        cin >> userinput;
        if (userinput == "Y")
        {
            int board_rows = 25;
            int board_columns = 5;
            int numberOfzombie = 2;
            srand(time(NULL));

            // displayDefaultGameSettings(board_rows, board_columns, numberOfzombie);

            Board board(board_rows, board_columns, numberOfzombie);
            board.random_items();
            board.create_character();
            board.alien_movement = true;
            board.display();
            board.commands();
        }
        else
        {
            quit();
        }
    }
    //------------Exit game------------//
    void quit()
    {
        string yesORno;

        cout << "End the game ? (Y/N) => ";
        cin >> yesORno;
        if (yesORno == "Y")
        {
            cout << "THANKS FOR PLAY" << endl;
            exit(0);
        }
        else if (yesORno == "N")
        {
            display();
            commands();
        }
        else
        {
            cout << "Please enter Y or N";
            quit();
        }
    }

    //------------Game's Commands------------//
    void commands()
    {
        string command;

        cout << "Command => ";
        cin >> command;

        if (command == "help")
        {
            cout << endl;
            cout << "Commands" << endl;
            cout << "1. up       - Move up" << endl;
            cout << "2. down     - Move down" << endl;
            cout << "3. left     - Move left" << endl;
            cout << "4. right    - Move right" << endl;
            cout << "5. arrow    - Change the direction of an arrow" << endl;
            cout << "6. help     - Display these user commands" << endl;
            cout << "7. save     - Save the game" << endl;
            cout << "8. load     - Load a game" << endl;
            cout << "9. quit     - Quit this game" << endl;
            returnback();
            display();
            commands();
        }
        else if (command == "up")
        {
            up();
            trail_reset();
            display();
            zombie_move();
        }
        else if (command == "down")
        {
            down();
            trail_reset();
            display();
            zombie_move();
        }
        else if (command == "left")
        {
            left();
            trail_reset();
            display();
            zombie_move();
        }
        else if (command == "right")
        {
            right();
            trail_reset();
            display();
            zombie_move();
        }
        else if (command == "arrow")
        {
            arrow();
        }
        else if (command == "save")
        {
            bool saved;
            saved = false;

            save();
            if (saved = true)
            {
                cout << "Game saved!";
            }
            else
            {
                cout << "Fail to save!";
            }
            commands();
        }
        else if (command == "load")
        {
            load();
        }
        else if (command == "quit")
        {
            quit();
        }
        else
        {
            cout << endl;
            cout << "Invalid input, please enter the correct input [up/down/left/right/arrow/help/save/load/quit]";
            cout << endl;
            commands();
        }
    }

    //------------Ask user to press any key to be continue----------------//
    void returnback()
    {
        cout << "Press any key to be continue . . . " << endl;
        cin.get();    // access the character array and it also includes the white space character inside the output.
        cin.ignore(); // ignore or clear one or more characters from the input buffer
        // cin.clear();
    }
};

//--------------display game setting-----------------//

void displayDefaultGameSettings(int &board_rows, int &board_columns, int &numberOfzombie)
{
    char choice;

    cout << endl;
    cout << "Default Game Settings" << endl;
    cout << "----------------------" << endl;
    cout << "Board Rows       :" << board_rows << endl;
    cout << "Board Columns    :" << board_columns << endl;
    cout << "Zombie Count     :" << numberOfzombie << endl;
    cout << endl;
    cout << "Do you wish to change the game settings (y/n)? =>" << choice;
    cin >> choice;
    choice = toupper(choice); // convert to uppercase

    if (choice == 'Y')
    {
        cout << "Board Settings" << endl;
        cout << "----------------" << endl;
        cout << "Enter rows => ";
        cin >> board_rows;
        while (board_rows % 2 == 0) // cannot use if else if not user can still enter even number
        {
            cout << endl;
            cout << "Please Enter Odd Nnumber Only." << endl;
            cout << "Enter rows => ";
            cin >> board_rows;
        }

        cout << "Enter Column =>";
        cin >> board_columns;
        while (board_columns % 2 == 0) // cannot use if else if not user can still enter even number
        {
            cout << endl;
            cout << "Please Enter Odd Number Only." << endl;
            cout << "Enter Columns => ";
            cin >> board_columns;
        }

        cout << endl;
        cout << "Zombie Settings" << endl;
        cout << "----------------" << endl;
        cout << "Enter number of zombies => ";
        cin >> numberOfzombie;
        cout << endl;

        cout << "Setting Updated.";
        cout << endl;
        cout << "Enter any key to continue . . .";
        cout << endl;
        cin.ignore(); // used to ignore or clear one or more characters from the input buffer
        cin.get();    // used to access the character array
    }

    else
    {
        cout << "Enter any key to continue . . .";
        cout << endl;
        cin.ignore();
        cin.get();
    }
}

int main()
{

    int board_rows = 25;
    int board_columns = 5;
    int numberOfzombie = 2;
    srand(time(NULL));

    displayDefaultGameSettings(board_rows, board_columns, numberOfzombie);

    Board board(board_rows, board_columns, numberOfzombie);
    board.random_items();
    board.create_character();
    board.alien_movement = true;
    board.display();
    board.commands();
}