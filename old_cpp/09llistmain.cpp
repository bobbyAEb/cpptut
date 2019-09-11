#include "09llist.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 10, y = 20;
    // cin >> x >> y;
    // PPOINT pt = PtCreate(x, y);
    PPOINT a[3];
    for (int i = 0; i < 3; ++i)
    {
        a[i] = PtCreate(x, y);
    }
    Linklist ywen;
    for (unsigned int i = 0; i < 3; ++i)
    {
        ywen.insert(a[i],i);
    }
    for (int i = 0; i < 3; ++i)
    {
        ywen.traverse();
        ywen.deleteLl(0);
    }
    cout << "ok" << endl;
    ywen.~Linklist();
    // Linklist ywen;
    for (int i = 0; i < 3; ++i)
    {
        a[i] = PtCreate(x, y);
    }
    for (unsigned int i = 0; i < 3; ++i)
    {
        ywen.insert(a[i],i);
        ywen.append(a[i]);
    }
    cout << ywen.getCount() << endl;
    ywen.traverse();
    return 0;
}
