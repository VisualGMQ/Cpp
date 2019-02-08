#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	vector<int> v{1,2,3,4,5,6,7,8};
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"find 7 in v:"<<*find(v.begin(),v.end(),7)<<endl;
	auto lambda = [](const int i){
		return i>=2 && i<=4;
	};
	cout<<"find elment between 2~4:"<<*find_if(v.begin(),v.end(),lambda)<<endl;
	cout<<"find element not between 2~4:"<<*find_if_not(v.begin(),v.end(),lambda)<<endl;

	v[4]=v[3]=v[2]=2;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"where 2 is continuly appear in v 3 times:"<<*search_n(v.begin(),v.end(),3,2)<<endl;
	cout<<"find adjacent elemnent value of 2:"<<*adjacent_find(v.begin(),v.end())<<endl;
	for(int i=0;i<v.size();i++)
		v[i]=i;
	vector<int> v2{4,5,6,7};
	ostream_iterator<int> o(cout," ");
	cout<<"v is:"<<endl;
	copy(v.begin(),v.end(),o);
	cout<<endl;
	cout<<"v2 is:"<<endl;
	copy(v2.begin(),v2.end(),o);
	cout<<endl;	
	
	cout<<"where v include v2:"<<*search(v.begin(),v.end(),v2.begin(),v2.end())<<endl;
	cout<<"the last section where v include v2:"<<*find_end(v.begin(),v.end(),v2.begin(),v2.end())<<endl;
	cout<<"the first section where v include v2:"<<*find_first_of(v.begin(),v.end(),v2.begin(),v2.end())<<endl;
	
	cout<<endl<<"compare section"<<endl;
	cout<<"is v equal to v2:"<<equal(v.begin(),v.end(),v2.begin())<<endl;
	cout<<"is v is a permutation fo v2:"<<is_permutation(v.begin(),v.end(),v2.begin())<<endl;
	cout<<"find the first different elements:"<<*mismatch(v.begin(),v.end(),v2.begin()).first<<","<<*mismatch(v.begin(),v.end(),v2.begin()).second<<endl;
	cout<<"compare less:"<<lexicographical_compare(v.begin(),v.end(),v2.begin(),v2.end())<<endl;

	cout<<endl<<"some calibrate function"<<endl;
	cout<<"is v sorted:"<<is_sorted(v.begin(),v.end())<<endl;
	cout<<"is v splited by 4:"<<is_partitioned(v.begin(),v.end(),[](const int i){
				return 	i<=4;
			})<<endl;
	cout<<"is v is a heap:"<<is_heap(v.begin(),v.end())<<endl;
	cout<<"is every element greater than 0:"<<all_of(v.begin(),v.end(),[](const int i){
			return i>0;
			})<<endl;
	cout<<"is no element equal 0:"<<none_of(v.begin(),v.end(),[](const int i){
			return i==0;
			})<<endl;
	cout<<"is any element less than 0:"<<any_of(v.begin(),v.end(),[](const int i){
			return i<0;
			})<<endl;
	return 0;
}
