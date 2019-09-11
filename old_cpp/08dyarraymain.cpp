#include "08dyarray.h"
#include <iostream>
#include "05random.h"
using namespace std;

int main()
{
    Randomize();
    PDARRAY tem;
    tem = DiCreat(10);
    for (int i = 0; i < 10; ++i)
    {
        DiInsert(tem, randnum(20, 50), i);
        cout << DiGetCapacity(tem) << " ";
        cout << DiGetCount(tem) << endl;
    }
    DiPrint(tem);
    DiInsert(tem, 9, 9);
    DiPrint(tem);
    DiInsert(tem, 11, 11);
    DiPrint(tem);
    DiInsert(tem, 0, 0);
    DiPrint(tem);
    DiInsert(tem, 33, 33);
    DiPrint(tem);
    return 0;
}
