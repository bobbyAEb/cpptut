#include <iomanip>
#include "08point.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y;
    char *t;
    PPOINT pt1, pt2;
    cin >> x >> y;
    pt1 = PtCreate(x, y);
    pt2 = pt1;
    PtSetValue(pt2, 19, 94);
    PtGetValue(pt2, &x, &y);
    cout << x << setw(4) << y << endl;
    t = PtTransformIntoString(pt2);
    PtPrint(pt2);
    cout << boolalpha << PtCompare(pt1, pt2);
    PtDestroy(pt1);
    PtPrint(pt1);
    pt1 = PtCreate(10,20);
    PtPrint(pt1);
    return 0;
}
