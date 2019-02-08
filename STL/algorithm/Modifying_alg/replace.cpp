#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;
using namespace placeholders;

int main(){
	vector<int> v(10);
	iota(v.begin(),v.end(),1);
	cout<<"v:";
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
	
	cout<<"replace every element bigger than 5 to 0:";
	replace_if(v.begin(),v.end(),bind(greater<int>(),_1,5),0);
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;

	vector<int> rpv(10);
	cout<<"replace and copy elements to rpv:";
	replace_copy(v.begin(),v.end(),rpv.begin(),0,10);
	for(auto i:rpv)
		cout<<i<<" ";
	cout<<endl;

	
}
