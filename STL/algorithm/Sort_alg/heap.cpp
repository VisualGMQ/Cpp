#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void print(const string msg,const vector<int>& v){
	cout<<msg;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	vector<int> v={2,1,3,7,6,4,5,8,9,10};
	print("v:",v);
	make_heap(v.begin(),v.end());
	print("change v to heap:",v);
	v.push_back(12);
	push_heap(v.begin(),v.end());
	print("push 12 into heap:",v);
	pop_heap(v.begin(),v.end());
	print("pop the max element to last of heap:",v);
	sort_heap(v.begin(),v.end());
	print("sort the heap to a sorted sequence:",v);
}

