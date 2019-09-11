#include "08ABlist.h"
#include <iostream>
#include "08point.h"

using namespace std;
/* 回调函数 DoPrintObject */
void DoPrintObject(ADT data, CADT tag)
{
    printf(PtTransformIntoString((PPOINT)data, (const char *)tag));
    printf(" -> ");
}
/* 调用 DoDestroyObject 函数释放 data 域指向的存储空间 */
void DoDestroyObject( ADT e )
{
delete (PPOINT)e;
}

int main()
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
        LlTraverse(t, DoPrintObject, "(%d,%d)");
        LlDelete(t, 0,DoDestroyObject);
    }
    cout << "ok" << endl;
    LlDestroy(t,DoDestroyObject);
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
    LlTraverse(t,DoPrintObject,"(%d,%d)");
    return 0;
}
