#ifndef LLIST_H
#define LLIST_H
#include "./old_cpp/08point.h"
struct NODE;
typedef struct NODE *PNODE;
class Linklist
{
  public:
    Linklist();
    ~Linklist();
    void append(PPOINT point);
    void insert(PPOINT point,unsigned int pos);
    void deleteLl(unsigned int pos);
    void traverse();
    bool search(PPOINT point);
    unsigned int getCount();
    bool isEmpty();
  private:
    int count;
    PNODE head;
    PNODE tail;
};

#endif