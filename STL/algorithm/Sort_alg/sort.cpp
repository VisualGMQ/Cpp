#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <random>
#include <numeric>
using namespace std;
using namespace placeholders;

void print(const char msg[],const vector<int>& v){
	cout<<msg;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	vector<int> v(7);
	iota(v.begin(),v.end(),1);
	default_random_engine dre;
	shuffle(v.begin(),v.end(),dre);
	print("v:",v);	
	sort(v.begin(),v.end());
	print("sorted v:",v);
	cout<<"stable_sort will not display"<<endl;
	shuffle(v.begin(),v.end(),dre);
	print("shffled v:",v);	
	partial_sort(v.begin(),v.begin()+3,v.end());
	print("partial_sort(v.begin(),v.begin()+3,v.end())",v);
	shuffle(v.begin(),v.end(),dre);
	print("shffuled v:",v);	
	nth_element(v.begin(),v.begin()+4,v.end());
	print("sort by v[4]:",v);
}
