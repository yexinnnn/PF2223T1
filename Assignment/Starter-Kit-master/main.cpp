// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: LIM YE XIN| TER ZEHNG BIN | LAI JIAN SENG
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
using namespace std;

class Zombie
{
public:
    int zombie_health;
    int zombie_attack;
    int zombie_range;

    Zombie()
    {
        // initailly zombie attribute
        zombie_health = 100;
        zombie_attack = 10;
        zombie_range = 2;
    }

    void zombie_attribute()
    {
        cout.width(5);
        cout << "Zombie   :  Health = ";
        cout.width(4);
        cout << zombie_health;
        cout << ", Attack : ";
        cout << zombie_attack;
        cout << ", Range  : ";
        cout << zombie_range << endl;
    }
};

class Alien
{
public:
    int alien_health;
    int alien_attack;

    Alien()
    {
        alien_health = 100;
        alien_attack = 10;
    }

    void alien_attribute()
    {
        // initailly zombie attribute

        cout.width(5);
        cout << "Alien    :  Health = ";
        cout.width(4);
        cout << alien_health;
        cout << ", Attack : ";
        cout << alien_attack << endl;
    }
};

class Board
{
private:
    vector<vector<char>> map_;
    int newRows_, newColumns_, newZombieCounts_;

public:
    Board(int board_rows, int board_columns, int numberOfzombie)
    {
        newRows_ = board_rows;
        newColumns_ = board_columns;
        newZombieCounts_ = numberOfzombie;
    }

    void init()
    {
        char control_items[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' '};
        int noOfcontrol_items = 12; // number of objects in the objects array
        // create dynamic 2D array using vector
        map_.resize(newColumns_); // create empty rows
        for (int i = 0; i < newColumns_; ++i)
        {
            map_[i].resize(newRows_); // resize each row
        }
        // put random characters into the vector array
        for (int i = 0; i < newColumns_; ++i)
        {
            for (int j = 0; j < newRows_; ++j)
            {
                int objNo = rand() % noOfcontrol_items; // randomly generate object
                map_[i][j] = control_items[objNo];
            }
        }
    }

    void display()
    {
        char control_items[] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' '};
        int noOfcontrol_items = 12;
        srand(time(NULL)); // randomly display generate items

        // comment this out during testing
        // system("cls"); // OR system("clear"); for Linux / MacOS
        cout.width(40);
        cout << "***Alien Vs Zombies***" << endl;

        // for each row
        for (int i = 0; i < newColumns_; ++i)
        {
            cout.width(4);
            // display upper border of the row
            cout << " ";
            for (int j = 0; j < newRows_; ++j) // dimX_ = 15，所以会重复15次
            {
                cout << "+-";
            }
            cout << "+" << endl;
            // display row number
            cout << setw(2) << (newColumns_ - i); // set width to 2， dimY_ = 5, 所以 5，4，3，2，1 出现在row

            // display cell content and border of each column
            cout.width(3);
            for (int j = 0; j < newRows_; ++j)
            {
                int objNo = rand() % noOfcontrol_items;
                cout << "|" << control_items[objNo]; // 开始之前先画一条线，之后才content然后线，以此类推，[row][column]
            }
            cout << "|" << endl;
        }

        // display lower border of the last row
        cout << " ";
        cout.width(5);
        for (int j = 0; j < newRows_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display column number
        cout << " ";
        cout.width(4);
        for (int j = 0; j < newRows_; ++j) // j == 0, from 0 until 14
        {
            int digit = (j + 1) / 10;
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
    }
    void returnback()
    {
        cout << "Press any key to be continue . . . " << endl;
        cin.get();
        cin.ignore();
        // cin.clear();
    }

        void alienposition()
    {
        cout << "(" << newRows_ / 2 + 1 << ", " << newColumns_ / 2 + 1 << ")" << endl;
        map_[newRows_ / 2][newColumns_ / 2] = 'A';

    }
    // Alien Alien();
    // alien.alien_attribute();
    // Zombie Zombie();
    // Zombie.zombie_attribute();

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
            cout << "5. arrow    - Change the directi9on of an arrow" << endl;
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
        }
        else if (command == "down")
        {
        }
        else if (command == "left")
        {
        }
        else if (command == "arrow")
        {
        }
        else if (command == "help")
        {
        }
        else if (command == "save")
        {
        }
        else if (command == "load")
        {
        }
        else if (command == "quit")
        {
        }
    }
};

//--------------display game setting-----------------//

void displayDefaultGameSettings(int &board_rows, int &board_columns, int &numberOfzombie)
{
    char choice;

    cout << endl;
    cout << "Default Game Settings" << endl;
    cout << "----------------------" << endl;
    cout << "Board Rows    :" << board_rows << endl;
    cout << "Board Columns :" << board_columns << endl;
    cout << "Zombie Count  :" << numberOfzombie << endl;
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
        cin.ignore(); // used to ignore or clear one or more characters from the input buffer
        cin.get();    // used to access the character array
    }
}

//--------------display attribute-----------------//
// viod displayAttribute()
// {
//     int Life;
//     int Attack;
//     int Range;
// }

// int health_pack(int hp)
// {
//     int health_p;
//     health_pack = 20;
//     return health_pack + hp;
// }

// viod get_h()
// {
//     int a_hp;
//     a_hp = 100;
//     if (a_hp >= 100)
//     {
//         a_hp = a_hp
//     }
//     else if (a_hp >= 80 || a_hp < 100)
//     {
//         a_hp = a_hp
//     }
//     else
//     {
//         a_hp = health_pack(a_hp);
//     }
//     cout << "Your Alian health recover to ";
//     cout << a_hp;
//     cout << endl;
// }

// int pod_atk(int hp)
// {
//     int atk;
//     atk = 20;
//     return hp - atk;
// }

// viod get_pod()
// {
//     int z_hp;
//     z_hp = 100;
//     if (z_hp >= 0)
//     {
//         z_hp = pod_atk(z_hp);
//         cout << " Alian has been attacked ";
//         // attack the nearest alian havent know how to do yet.....
//     }
//     if (z_hp <= 0 || z_hp == 0)
//     {
//         z_hp = 0 cout << "Alian dead! HoRay";
//     }
// }

// viod get_rock()
// {
//     // Hrm....No value need be be counted and deducted bah? not sure
// }

int main()
{

    int board_rows = 25;
    int board_columns = 5;
    int numberOfzombie = 1;
    srand(time(NULL));

    displayDefaultGameSettings(board_rows, board_columns, numberOfzombie); // --- Get settings

    Board board(board_rows, board_columns, numberOfzombie);
    board.display();
    Alien alien;
    alien.alien_attribute();
    Zombie zombie;
    zombie.zombie_attribute();
    board.commands();
}
