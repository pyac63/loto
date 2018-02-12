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

