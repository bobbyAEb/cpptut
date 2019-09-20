/* 点库实现 “ point.cpp”*/
#include "08point.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
static char *DuplicateString(const char *s);
struct POINT {
  int x;
  int y;
};
typedef struct POINT *PPOINT;

PPOINT PtCreate(int x, int y) {
  PPOINT t = new POINT;
  t->x = x;
  t->y = y;
  return t;
}
void PtDestroy(PPOINT point) {
  if (point) {
    delete point;
    point = nullptr;
  }
}
void PtGetValue(PPOINT point, int *x, int *y) {
  if (point) {
    if (*x) {
      *x = point->x;
    }
    if (*y) {
      *y = point->y;
    }
  }
}
void PtSetValue(PPOINT point, int x, int y) {
  if (point) {
    point->x = x;
    point->y = y;
  }
}
bool PtCompare(PPOINT point1, PPOINT point2) {
  if (!point1 || !point2) {
    cout << "parameters illegal" << endl;
    exit(1);
  }
  return (point1->x == point2->x && point1->y == point2->y);
}
char *PtTransformIntoString(PPOINT point, const char *tag) {
  char buf[BUFSIZ];
  sprintf(buf, tag, point->x, point->y);
  return DuplicateString(buf);
}
char *DuplicateString(const char *s) {
  int n = strlen(s);
  char *t = new char[n + 1];
  for (int i = 0; i < n; ++i) {
    t[i] = s[i];
  }
  t[n] = '\0';
  return t;
}
void PtPrint(PPOINT point) { printf("(%d,%d)", point->x, point->y); }