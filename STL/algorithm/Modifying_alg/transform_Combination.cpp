#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;
using namespace placeholders;

void print(const vector<int>& v){
	ostream_iterator<int> o(cout," ");
	copy(v.begin(),v.end(),o);
	cout<<endl;
}

int main(){
	vector<int> v={1,2,3,4,5,6,7},tv(7),cov(7);
	cout<<"v:";
	print(v);
	cout<<"copy v to tv and mutiply elements 2 in v:";
	transform(v.begin(),v.end(),tv.begin(),bind(multiplies<int>(),_1,2));
	print(tv);
	cout<<"copy v's elements + tv's elements to nv:";
	vector<int> nv(7);
	transform(v.begin(),v.end(),tv.begin(),nv.begin(),bind(plus<int>(),_1,_2));
	print(nv);
}
