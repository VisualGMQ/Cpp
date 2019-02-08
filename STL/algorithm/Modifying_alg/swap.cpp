#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> v={1,2,3,4,5,6,7},sv(7);
	cout<<"v:";
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	swap_ranges(v.begin(),v.end()-3,sv.begin());
	cout<<"swap v and a part of sv"<<endl;
	cout<<"v:";
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"sv:";
	for(int i:sv)
		cout<<i<<" ";
	cout<<endl;
		
}
