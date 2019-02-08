#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(const char msg[40],const vector<int>& v){
	cout<<msg;
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	vector<int> v1={3,7,4,1,2,0,9,8},v2={0,9,-1,-2,4,5,8};
	cout<<"all function below is point at sorted container!!!"<<endl;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	print("v1:",v1);
	print("v2:",v2);
	vector<int> rv(v1.size()+v2.size());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),rv.begin());
	print("merged v1 and v2:",rv);
	fill(rv.begin(),rv.end(),0);
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),rv.begin());
	print("find the union of v1 and v2:",rv);
	fill(rv.begin(),rv.end(),0);
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),rv.begin());
	print("find the intersection of v1 and v2:",rv);
	fill(rv.begin(),rv.end(),0);
	set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),rv.begin());
	print("find the difference of v1 and v2:",rv);
}
