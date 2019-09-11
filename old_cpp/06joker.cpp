//#define NDEBUG
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include<ctime>

using namespace std;

int randint(int lowerbound, int highbound)
{
    double _n;
    //Randomize();
    if (highbound < lowerbound)
    {
        cout << "wrong boundaries" << endl;
        return -1;
    }
    _n = (double)rand() / ((double)RAND_MAX + 1.0);
    return (lowerbound + (int)(_n * (highbound - lowerbound + 1)));
}
int color()
{
    return randint(0, 3);
}

int number()
{
    return randint(1, 13);
}

int makeJoker(int numbers, int colors)
{
    //int numbers,colors;
    switch (colors)
    {
    case 0:
        return numbers;
    default:
        return colors * 13 + numbers;
    }
}
int value(int a)
{
    switch (a)
    {
    case 10:
        return 1;
    case 11:
        return 2;
    case 12:
        return 3;
    case 13:
        return 4;
    default:
        return 0;
    }
}
int count(int a[], int elem_num)
{
    int i, total;
    for (i = 0; i < elem_num; i++)
    {
        total += value(a[i]);
    }
    return total;
}

int main()
{

    enum GRADE
    {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        T,
        J,
        Q,
        K,
        A
    };
    struct CARDS
    {
        int grade;
        int jokers[13];
    };
    int num, i, j, cards = 0, joker_index;
    int colors, numbers;
    bool card[52];
    CARDS players[4];
    //发牌
    srand((unsigned)(time(NULL)));
    for (j = 0; j < 13; j++)
    {
        for (i = 0; i < 4; i++)
        {
            while (true)
            {
                numbers = number();
                colors = color();
                joker_index = makeJoker(numbers, colors);
                if (!card[joker_index])
                {
                    players[i].jokers[j] = numbers;
                    card[joker_index] = true;
                    cards++;
                    break;
                }
            }
        }
    }
    //积分
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 13; j++)
        {
            cout << setw(3) << players[i].jokers[j];
        }

        players[i].grade = count(players[i].jokers, 13);
        cout << setw(3) << players[i].grade << endl;
    }
    return 0;
}