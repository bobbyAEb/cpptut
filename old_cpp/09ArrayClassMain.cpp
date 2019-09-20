#include <iostream>
#include "./old_cpp/05random.h"
#include "09ArrayClass.h"
using namespace std;

int main() {
  unsigned int n = 10;
  Randomize();
  Darray ywen(n);
  for (int i = 0; i < 10; ++i) {
    ywen.DiInsert(randnum(20, 50), i);
    cout << ywen.DiGetCapacity() << " ";
    cout << ywen.DiGetCount() << endl;
  }
  ywen.DiPrint();
  ywen.DiInsert(9, 9);
  ywen.DiPrint();
  ywen.DiInsert(11, 11);
  ywen.DiPrint();
  ywen.DiInsert(0, 0);
  ywen.DiPrint();
  ywen.DiInsert(33, 33);
  ywen.DiPrint();
  return 0;
}
