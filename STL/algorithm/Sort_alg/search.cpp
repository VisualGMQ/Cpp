#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(const char msg[40],const vector<int> v){
	cout<<msg<<endl;
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	vector<int> v={3,6,4,9,0,1,2};
	print("v:",v);
	cout<<"binary search 9 in v:"<<binary_search(v.begin(),v.end(),9);
	vector<int> iv={3,6,4,9};
	print("iv:",iv);
	cout<<"is v include iv:"<<includes(v.begin(),v.end(),iv.begin(),iv.end())<<endl;
	cout<<"find the last element lower than 9 in v:"<<distance(v.begin(),lower_bound(v.begin(),v.end(),9))<<endl;
	cout<<"find the first element bigger than 9 in v:"<<distance(v.begin(),upper_bound(v.begin(),v.end(),9))<<endl;
	return 0;
}
