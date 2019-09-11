#include "08list.h"
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
    PLIST t = LlCreate();
    for (unsigned int i = 0; i < 3; ++i)
    {
        LlInsert(t, a[i], i);
    }
    for (int i = 0; i < 3; ++i)
    {
        LlTraverse(t);
        LlDelete(t, 0);
    }
    cout << "ok" << endl;
    LlDestroy(t);
    t = LlCreate();
    for (int i = 0; i < 3; ++i)
    {
        a[i] = PtCreate(x, y);
    }
    for (unsigned int i = 0; i < 3; ++i)
    {
        LlInsert(t, a[i], i);
        LlAppend(t, a[i]);
    }
    cout << LlGetCount(t) << endl;
    LlTraverse(t);
    return 0;
}
