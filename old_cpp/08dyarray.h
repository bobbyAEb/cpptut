#ifndef DARRAY_H
#define DARRAY_H

struct DARRAY;
typedef struct DARRAY* PDARRAY;

PDARRAY DiCreat(unsigned int n);
void DiDestroy(PDARRAY pd);
int DiGetvalue(PDARRAY pd, unsigned int pos);
void DiInsert(PDARRAY pd, int value, unsigned int pos);
unsigned int DiGetCount(PDARRAY pd);
unsigned int DiGetCapacity(PDARRAY pd);
void DiPrint(PDARRAY pd);
#endif