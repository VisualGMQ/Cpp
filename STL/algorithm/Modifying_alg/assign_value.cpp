#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;
using namespace placeholders;

int main(){
	vector<int> v(7);
	cout<<"fill v with 1:";
	fill(v.begin(),v.end(),1);
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"fill v with 2 range 5:";
	fill_n(v.begin(),5,2);
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"assign v with a raise sequence:";
	generate(v.begin(),v.end(),[](){static int i=1;i*=2;return i;});
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	cout<<"give v a increments values:";
	iota(v.begin(),v.end(),10);
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;
	
}
