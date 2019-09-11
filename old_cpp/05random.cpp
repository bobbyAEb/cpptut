#include <iostream>
#include <cstdlib>
#include <ctime>
#include "05random.h"
using namespace std;
void  Randomize()
{
  srand((int)(time(NULL)));
}

int randnum(int low,int high)
{
  double _d;
  if (low>high){
    cout<<"high bound lower than low bound"<<endl;
    exit(1);
  }
  _d=(double)rand()/((double)RAND_MAX+1.0);
  return (low+(int)(_d*(high-low+1)));
}  
double randreal(double low, double high)
{
  double _d;
  if (low>high){
    cout<<"high bound lower than low bound"<<endl;
    exit(2);
  }
  _d=(double)rand()/(double)RAND_MAX;
  return (low+_d*(high-low));
  
}
