#include "09llist.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

struct NODE
{
    PPOINT data; /* 当前结点的存储数据 */
    PNODE next;  /* 指向下一结点,表尾此域为 NULL */
};
Linklist::Linklist()
{
    this->count = 0;
    this->head = nullptr;
    this->tail = nullptr;
}
Linklist::~Linklist()
{
    while (this->head)
    {
        PNODE tem = this->head;
        this->head = tem->next;
        PtDestroy(tem->data);
        delete tem;
        tem = nullptr;
        --this->count;
    }
    this->tail = nullptr;
}
void Linklist::append(PPOINT point)
{
    if (!point)
    {
        cout << "LlAppend: Parameter illegal." << endl;
        exit(1);
    }
    PNODE tem = new NODE;
    tem->data = point;
    tem->next = nullptr;
    if (this->count == 0)
    {
        this->head = tem;
        this->tail = tem;
    }
    else
    {
        this->tail->next = tem;
        this->tail = tem;
    }
    this->count++;
}

void Linklist::insert(PPOINT point, unsigned int pos)
{
    if (!point)
    {
        cout << "LlInsert: Parameter illegal." << endl;
    }
    PNODE tem = new NODE;
    tem->data = point;
    // pos < count 就可以判断这个链表是不是空的，若为空则由append函数来接着判断；
    if (pos < this->count)
    {
        if (pos == 0)
        {
            tem->next = this->head;
            this->head = tem;
        }
        else
        {
            PNODE t = this->head;
            for (unsigned int i = 1; i < pos; ++i)
            {
                t = t->next;
            }
            tem->next = t->next;
            t->next = tem;
        }
        this->count++;
    }
    else
    {
        Linklist::append(point);
    }
}
void Linklist::deleteLl (unsigned int pos)
{
    if (this->count == 0)
    {
        return;
    }
    if (pos == 0)
    {
        PNODE tem = this->head;
        this->head = tem->next;

        if (!this->head)
        {
            this->tail = nullptr;
        }
        PtDestroy(tem->data);
        delete tem;
        tem = nullptr;
    }
    else if (pos < this->count)
    {
        PNODE tem = this->head, tt;
        for (unsigned int i = 1; i < pos; ++i)
        {
            tem = tem->next;
        }
        tt = tem->next;
        tem->next = tt->next;
        if (!tem->next)
        {
            this->tail = tem;
        }
        PtDestroy(tem->next->data);
        delete tem->next;
        tem->next = nullptr;
    }
    --this->count;
}
void Linklist::traverse()
{
    PNODE tt = this->head;

    while (tt)
    {
        cout << PtTransformIntoString(tt->data,"(%d, %d)") << "->";
        tt = tt->next;
    }
    cout << "null\n";
}
bool Linklist::search(PPOINT point)
{
    if (!point)
    {

        cout << "LlSearch: Parameter illegal." << endl;
    }
    PNODE tem = this->head;
    while (tem)
    {
        if (PtCompare(tem->data, point))
        {
            return true;
        }
        tem = tem->next;
    }
    return false;
}
unsigned int Linklist::getCount()
{
    return this->count;
}
bool Linklist::isEmpty()
{
    if (this->count > 0)
    {
        return false;
    }
    return true;
}