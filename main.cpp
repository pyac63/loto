#include <iostream>
#include <random>
#include <ctime>
#include "def.h"


using namespace std;


int main()
{
    int number = 6;
    int money = 100;

    cout << "*\tWelcome to the Loto Game!\t*\n";
    cout << "*\tYou have 100$ to spend.\t\t*\n";
    cout << "*\tChoose your six lucky numbers!\t*\n\n";


    while (1)
    {
        int array1[number];
        for (int a = 0; a < number; a++)
        {
            array1[a] = choose();
            cout << "You choose: " << array1[a] << '\n';
        }

        int array3[number];
        for (int a = 0; a < number; a++)
        {
            array3[a] = draw();
        }

        int com = 0;
        for (int x = 0; x < number; x++)
        {
            for (int y = 0; y < number; y++)
            {
                if (array1[x] == array3[y])
                    com++;
            }
        }

        int bet = getBet(money);
        money -= bet;

        int cashTurn = cashReturn(bet, com);
        if (com > 0)
        {
            money += cashTurn;

        }
        if (money <= 0)
            break;
        else
            cout << "You now have " << money << " $!\n\n";
    }

    cout << "You do not have any money left...the game is over !\n";
    return 0;
}
