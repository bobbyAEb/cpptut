#include <iostream>
#include <iomanip>

using namespace std;

enum WEEK{SUN, MON, TUE, WED, THU, FRI, SAT};

int main()
{
    int length,day;
    const WEEK day_1=FRI;
    length=31;
    WEEK weekday;
    cout << "Calendar 2006-01\n";
    cout << "--------------------------\n";
    cout << "Su Mo Tu We Th Fr Sa\n";
    cout << "--------------------------\n";
    cout << setw(3*((int)day_1+1)-1)<<1;
    for (day=2;day<=length;day++){
        weekday=(WEEK)((day+(int)day_1-1)%7);        
	/* 在指定位置输出该日的星期几信息 */
        if( weekday == SUN )
          cout << setw(2) << day;
        else if( weekday == MON )
          cout << setw(3) << day;
        else if( weekday == TUE )
          cout << setw(3) << day;
        else if( weekday == WED )
          cout << setw(3) << day;
        else if( weekday == THU )
          cout << setw(3) << day;
        else if( weekday == FRI )
          cout << setw(3) << day;
        else
          cout << setw(3) << day<<"\n";
        
    }
    cout << endl << "--------------------------\n";
    return 0;
    
}
