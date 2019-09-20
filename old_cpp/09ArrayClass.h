#ifndef DARRAY_H
#define DARRAY_H

class Darray {
 public:
  Darray(unsigned int n);
  ~Darray();
  void DiInsert(int value, unsigned int pos);
  int DiGetvalue(unsigned int pos);
  unsigned int DiGetCount();
  unsigned int DiGetCapacity();
  void DiPrint();

 private:
  int count;
  int capacity;
  int *items;
};

#endif