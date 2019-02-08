#include <iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include <utility>
using namespace std;

int main(){
	vector<int> v{1,2,3,4,5,6,7};
	cout<<"the v is:"<<endl;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"the min element in v:"<<*min_element(v.begin(),v.end())<<endl		<<"the max element in v:"<<*max_element(v.begin(),v.end())<<endl;
	auto mm = minmax_element(v.begin(),v.end());	
	cout<<"the min&max element in v:"<<*mm.first<<'&'<<*mm.second<<endl
	<<"the distance is:"<<distance(mm.first,mm.second)<<endl;
	return 0;
}
