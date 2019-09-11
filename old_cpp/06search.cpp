#include <iostream>
#include <cstdlib>
#include <iomanip>

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

bool search(int a[], int elem_num, int num)
{
    int i;
    for (i = 0; i < elem_num; i++)
    {
        if (a[i] == num)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    int elem_num, num, i, j;
    bool result;
    cout << "please input a random integer,it will return an unsorted array" << endl;
    cin >> elem_num;
    int a[elem_num];
    for (i = 0; i < elem_num; i++)
    {
        a[i] = randint(1, 100);
        cout << a[i] << setw(3);
    }
    cout << "\n";
    cout << "please input a single number to see whether it is in the array or not" << endl;
    cin >> num;
    result = search(a, elem_num, num);
    cout << boolalpha << result;
    cout << endl;
    return 0;
}