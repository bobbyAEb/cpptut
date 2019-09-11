#define NDEBUG
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int failed_in_testing_primality = 1;
bool Isprime(unsigned int n);
bool Factor(unsigned int n);
int main ()
{
  unsigned int n;
  cout << "please input a random integer, and the programme will return" 
       << "a equation includes the integer you input and all its prime factors"<<endl;
  while (cin>>n){
    if (n<=1){
    cout << "IsPrime: Failed in testing the primality of " << n<< endl;
    exit( failed_in_testing_primality );
    } 
#ifndef NDEBUG
    if (Isprime(n)){
      cout<<"true"<<endl;
    } else {
      cout<<"false"<<endl;
    }
#endif
    if (Isprime(n)){
      cout<<n<<"="<<n<<endl;
    } else{
      cout<<n<<"=";
      Factor(n);
      cout<<endl;
    }
  }    
  return 0;
} 

bool Isprime(unsigned int n)
{
  const int t=int(sqrt(n))+1;
  unsigned int factor=2;
  if (n==2){
    return true;
  }
  while (factor<t){
    if (n%factor==0){
       return false;
    } 
   
    factor ++;
  }
  return true;
}

bool Factor(unsigned int n)
{
  int i=2;
  bool found=false;
  if (n==1){
    return false;
  } else{
    const int t=int(sqrt(n))+1;
    while (! found){
      if (Isprime(i) && n%i==0){
        found=true;
        if (Factor(n/i)){
          cout<<"*";
        }
        cout<<i;
      }
      i++;
    }
  return true;
  }
}

