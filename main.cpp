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

int main()
{
    int number = 6;
    int money = 100;

    cout << "Welcome to the Loto Game!" << endl;
    cout << "You have 100$ to spend.\n";
    cout << "Choose your six lucky numbers!\n";


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
    cout << "You found " << com << " good numbers!\n";
    return 0;
}
