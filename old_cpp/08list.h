#include "08point.h"
struct LIST;
typedef struct LIST * PLIST;
PLIST LlCreate();
void LlDestroy( PLIST list );
void LlAppend( PLIST list, PPOINT point );
void LlInsert( PLIST list, PPOINT point, unsigned int pos );
void LlDelete( PLIST list, unsigned int pos );
void LlClear( PLIST list );
void LlTraverse( PLIST list );
bool LlSearch( PLIST list, PPOINT point );
unsigned int LlGetCount( PLIST list );
bool LlIsEmpty( PLIST list );