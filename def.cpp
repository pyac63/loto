#include <iostream>
#include <random>
#include <ctime>

using namespace std;


int getRandomNumber(int min, int max)
{
	static std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // initialize our mersenne twister with a random seed
	static const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
	return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
}

int draw()
{
    return getRandomNumber(1,49);
}

int choose()
{
    cout << "Enter your number: \n";
    int a;
    cin >> a;
    return a;
}

int getBet(int total)
{
    while (1)
    {
        cout << "How much do you want to bet ?\n";
        int x;
        cin >> x;
        if (x > total)
        {
            cout << "You don't have enough money !\n";
        }

        else if (x <= 0)
        {
            cout << "You have to bet something !\n";
        }

        else
        {
            cout << "You will bet " << x << " $.\n";
            return x;
        }

    }


}

int cashReturn (int bet, int com)
{
    if (com == 0)
    {
        cout << "Sorry, you have no good numbers...\n";
        return bet;
    }

    else
    {
        cout << "Congratulations! You guessed " << com << " good numbers!\n";
        int cash = (bet*com)*com;
        cout << "You won " << cash << " $!\n";
        return cash;
    }
}
