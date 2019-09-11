#include <iostream>
#include <iomanip>
#include "Sales_item.h"

using namespace std;

int main()
{
	Sales_item item1,item2;
	cout<<"输入书籍信息：\n";
	cout<<"ISBN"<<"	"<<"number"<<"	"<<"price"<<endl;
	cin>>item1>>item2;
	if (item1.isbn()==item2.isbn())
		cout<<item1+item2<<endl;
	else
		cerr<<"error"<<endl;
	while (cin>>item1)			
		cout<<item1<<endl; 
	return 0;
}
