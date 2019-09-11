#include <iostream>
#include "08dyarray.h"

using namespace std;
struct DARRAY
{
    int count;
    int capacity;
    int *items;
};

typedef struct DARRAY *PDARRAY;

PDARRAY DiCreat(unsigned int n)
{
    PDARRAY tem = new DARRAY;
    tem->capacity = n;
    tem->count = 0;
    tem->items = new int[n];
    return tem;
}
void DiDestroy(PDARRAY pd)
{
    if (!pd)
    {
        cout << "DiDestroy: Parameter illegal." << endl;
        exit(1);
    }
    if (pd->items)
    {
        delete[] pd->items;
        pd->items = nullptr;
    }
    delete pd;
    pd = nullptr;
}

void DiInsert(PDARRAY pd, int value, unsigned int pos)
{
    if (!pd || !pd->items)
    {
        cout << "DiInsert: Parameter illegal." << endl;
        exit(1);
    }
    int i;

    if (pd->count == pd->capacity)
    {
        if (pos >= pd->capacity)
        {
            pos = pd->capacity;
        }
        int *tem = new int[pd->count + 1];
        for (i = 0; i < pos; ++i)
        {
            tem[i] = pd->items[i];
        }
        tem[pos] = value;
        for (i = pos; i < pd->capacity; ++i)
        {
            tem[i + 1] = pd->items[i];
        }
        delete[] pd->items;
        pd->items = tem;
        ++pd->capacity;
        ++pd->count;
    }
    else
    {
        if (pos >= pd->count)
        {
            pd->items[pd->count] = value;
        }
        else
        {
            for (i = pd->count; i < pos + 1; --i)
            {
                pd->items[i] = pd->items[i - 1];
            }
            pd->items[pos] = value;
        }
        ++pd->count;
    }
}
int DiGetvalue(PDARRAY pd, unsigned int pos)
{
    if (!pd || !pd->items)
    {
        cout << "DiGetvalue: Parameter illegal." << endl;
        exit(1);
    }
    return pd->items[pos];
}
unsigned int DiGetCount(PDARRAY pd)
{
    if (!pd)
    {
        cout << "DiGetCount: Parameter illegal." << endl;
        exit(1);
    }
    return pd->count;
}

unsigned int DiGetCapacity(PDARRAY pd)
{
    if (!pd)
    {
        cout << "DiGetCapacity: Parameter illegal." << endl;
        exit(1);
    }
    return pd->capacity;
}
void DiPrint(PDARRAY pd)
{
    if (!pd || !pd->items)
    {
        cout << "DiPrint: Parameter illegal." << endl;
        exit(1);
    }

    int *tem = pd->items;
    cout << "[";
    for (int i = 0; i < pd->count - 1; ++i)
    {
        cout << tem[i] << ", ";
    }
    cout << tem[pd->count - 1] << "]" << endl;
}