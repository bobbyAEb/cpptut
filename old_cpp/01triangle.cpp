#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int lines,dis,length;
	int i,j;
	cout<<"图形demo：\n"
			<<"   *   *****\n"
			<<"  ***   ***\n"
			<<" *****   *\n"
			<<"\n"
			<<"请输入打印行数和间距："<<endl;
	cin>>lines>>dis;
	for (i=1;i<=lines;i++){
		for (j=1;j<=lines-i+1;j++)
			cout<<" ";
		for (j=0;j<2*i-1;j++)
			cout<<"*";
		for (j=0;j<dis;j++)
			cout<<" ";
		for (j=0;j<2*(lines-i+1)-1;j++)
			cout<<"*";
    cout<<"\n"<<endl;
  }
	return 0;
}
