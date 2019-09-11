/* 点库接口 “ point.h”*/
struct POINT;
typedef struct POINT * PPOINT;
PPOINT PtCreate( int x, int y );
void PtDestroy( PPOINT point );
void PtGetValue( PPOINT point, int * x, int * y );
void PtSetValue( PPOINT point, int x, int y );
bool PtCompare( PPOINT point1, PPOINT point2 );
char *PtTransformIntoString(PPOINT point, const char *tag);
void PtPrint( PPOINT point );