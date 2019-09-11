#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int m = 1, n = 2, t;
    int *p = &m, *q = &n;
    t = *p;
    *p = *q;
    *q = t;
    cout << m << n << endl;
    return 0;
}
