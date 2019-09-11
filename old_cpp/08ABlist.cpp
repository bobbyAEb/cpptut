#include "08ABlist.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
struct NODE;
typedef struct NODE *PNODE;
struct NODE
{
    ADT data;   /* 当前结点的存储数据 */
    PNODE next; /* 指向下一结点,表尾此域为 NULL */
};
struct LIST
{
    unsigned int count; /* 链表中包含的结点数目 */
    PNODE head, tail;   /* 链表头尾指针 */
};
typedef struct LIST *PLIST;

PLIST LlCreate()
{
    PLIST t = new LIST;
    t->count = 0;
    t->head = nullptr;
    t->tail = nullptr;
    return t;
}
void LlDestroy(PLIST list, DESTROY_OBJECT destroy)
{
    if (list)
    {
        LlClear(list, destroy);
        delete list;
        list = nullptr;
    }
}
void LlAppend(PLIST list, ADT object)
{
    if (!list || !object)
    {
        cout << "LlAppend: Parameter illegal." << endl;
        exit(1);
    }
    PNODE t = new NODE;
    t->data = object;
    t->next = nullptr;
    if (list->count == 0)
    {
        list->head = t;
        list->tail = t;
    }
    else
    {
        list->tail->next = t;
        list->tail = t;
    }
    list->count++;
}
void LlInsert(PLIST list, ADT object, unsigned int pos)
{
    if (!list || !object)
    {
        cout << "LlInsert: Parameter illegal." << endl;
    }
    PNODE t = new NODE;
    t->data = object;
    // pos < count 就可以判断这个链表是不是空的，若为空则由append函数来接着判断；
    if (pos < list->count)
    {
        if (pos == 0)
        {
            t->next = list->head;
            list->head = t;
        }
        else
        {
            PNODE tem = list->head;
            for (unsigned int i = 1; i < pos; ++i)
            {
                tem = tem->next;
            }
            t->next = tem->next;
            tem->next = t;
        }
        list->count++;
    }
    else
    {
        LlAppend(list, object);
    }
}
void LlDelete(PLIST list, unsigned int pos, DESTROY_OBJECT destroy)
{
    if (!list)
    {
        cout << "LlDelete: Parameter illegal." << endl;
    }
    if (list->count == 0)
    {
        return;
    }
    if (pos == 0)
    {
        PNODE tem = list->head;
        list->head = tem->next;

        if (!list->head)
        {
            list->tail = nullptr;
        }
        if (destroy)
        {
            (*destroy)(tem->data);
        }
        delete tem;
        tem = nullptr;
    }
    else if (pos < list->count)
    {
        PNODE tem = list->head, t;
        for (unsigned int i = 1; i < pos; ++i)
        {
            tem = tem->next;
        }
        t = tem->next;
        tem->next = t->next;
        if (!tem->next)
        {
            list->tail = tem;
        }
        if (destroy)
        {
            (*destroy)(tem->data);
        }
        delete tem->next;
        tem->next = nullptr;
    }
    --list->count;
}
void LlClear(PLIST list, DESTROY_OBJECT destroy)
{
    while (list->head)
    {
        PNODE t = list->head;
        list->head = t->next;
        if (destroy)
        {
            (*destroy)(t->data);
        }
        delete t;
        t = nullptr;
        --list->count;
    }
    list->tail = nullptr;
}
void LlTraverse(PLIST list, MANIPULATE_OBJECT manipulate, CADT tag)
{
    PNODE t = list->head;
    if (!list)
    {
        cout << "LlTraverse: Parameter illegal." << endl;
    }
    while (t)
    {
        if (manipulate)
        {
            (*manipulate)(t->data, tag);
        }
        else
        {
            cout << t->data << "->";
        }
        t = t->next;
    }
    cout << "null\n";
}
bool LlSearch(PLIST list, ADT object, COMPARE_OBJECT compare)
{
    if (!list || !object)
    {

        cout << "LlSearch: Parameter illegal." << endl;
    }
    PNODE t = list->head;
    while (t)
    {
        if (compare(t->data, object))
        {
            return true;
        }
        t = t->next;
    }
    return false;
}
unsigned int LlGetCount(PLIST list)
{
    if (!list)
    {
        exit(1);
    }
    return list->count;
}
bool LlIsEmpty(PLIST list)
{
    if (!list)
    {
        exit(1);
    }
    if (list->count > 0)
    {
        return false;
    }
    return true;
}