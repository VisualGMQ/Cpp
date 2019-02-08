#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
using namespace placeholders;

int main(){
	cout<<"every remove function will not change the containers' size,only return the end iterator!!!"<<endl;
	vector<int> v(10);
	iota(v.begin(),v.end(),1);
	cout<<"v:";
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;

	cout<<"remove elements > 5:";
	auto it=remove_if(v.begin(),v.end(),bind(greater<int>(),_1,5));
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"use erase to change the size:";
	v.erase(it,v.end());
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;

	vector<int> rpv(10);
	cout<<"copy and remove elements(remove 3):";
	remove_copy(v.begin(),v.end(),rpv.begin(),3);
	for(int i:rpv)
		cout<<i<<" ";
	cout<<endl;

	cout<<"remove consecutive elements in rpv:";
	it = unique(rpv.begin(),rpv.end());
	for(int i:rpv)
		cout<<i<<" ";
	cout<<endl;
	cout<<"change the rpv's size:";
	rpv.erase(it,rpv.end());
	for(int i:rpv)
		cout<<i<<" ";
	cout<<endl;
	
	cout<<"unique_copy() & unique_copy_if() will not display"<<endl;
}
