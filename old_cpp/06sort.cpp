#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int randint(int lowerbound,int highbound){
    double _n;
    //Randomize();
    if (highbound<lowerbound){
        cout<<"wrong boundaries"<<endl;
        return -1;
    }
    _n=(double)rand()/((double)RAND_MAX+1.0);
    return (lowerbound+(int)(_n*(highbound-lowerbound+1)));    
}

void swap(int a[],int i,int j){
    int t;
    t=a[i];a[i]=a[j];a[j]=t;
}



int main(int argc, char const *argv[])
{
    int num,i,j;
    cout<<"please input a random integer,it will return an unsorted array"<<endl;
    cin>>num;
    int a[num];
    for(i=0;i<num;i++){
        a[i]=randint(1,100);
        cout<<setw(3)<<a[i];
    }
    cout<<"\n";
    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if(a[i]<a[j]){
                swap(a,i,j);
            }
        }
    }
    for(i=0;i<num;i++){
        cout<<setw(3)<<a[i];
    }
    cout<<endl;
    
    return 0;
}