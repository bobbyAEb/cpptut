#include "09ArrayClass.h"
#include <iostream>

using namespace std;

Darray::Darray(unsigned int n) {
  this->items = new int[n];
  this->count = 0;
  this->capacity = n;
}
Darray::~Darray() {
  if (this->items) delete[] this->items;
  this->items = nullptr;
}
void Darray::DiInsert(int value, unsigned int pos) {
  if (!this->items) {
    cout << "DiInsert: Parameter illegal." << endl;
    exit(1);
  }
  int i;

  if (this->count == this->capacity) {
    if (pos >= this->capacity) {
      pos = this->capacity;
    }
    int *tem = new int[this->count + 1];
    for (i = 0; i < pos; ++i) {
      tem[i] = this->items[i];
    }
    tem[pos] = value;
    for (i = pos; i < this->capacity; ++i) {
      tem[i + 1] = this->items[i];
    }
    delete[] this->items;
    this->items = tem;
    ++this->capacity;
    ++this->count;
  } else {
    if (pos >= this->count) {
      this->items[this->count] = value;
    } else {
      for (i = this->count; i < pos + 1; --i) {
        this->items[i] = this->items[i - 1];
      }
      this->items[pos] = value;
    }
    ++this->count;
  }
}

int Darray::DiGetvalue(unsigned int pos) {
  if (!this->items) {
    cout << "DiGetvalue: Parameter illegal." << endl;
    exit(1);
  }
  return this->items[pos];
}
unsigned int Darray::DiGetCount() { return this->count; }

unsigned int Darray::DiGetCapacity() { return this->capacity; }

void Darray::DiPrint() {
  if (!this->items) {
    cout << "DiPrint: Parameter illegal." << endl;
    exit(1);
  }

  cout << "[";
  for (int i = 0; i < this->count - 1; ++i) {
    cout << this->items[i] << ", ";
  }
  cout << this->items[this->count - 1] << "]" << endl;
}