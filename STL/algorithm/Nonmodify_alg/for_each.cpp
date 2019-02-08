#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;

void output(vector<int>& v){
	ostream_iterator<int> o(cout,",");
	copy(v.begin(),v.end(),o);
			
}

int main(){
	vector<int> v{1,2,3,4,5,6,7};
	cout<<"for_each using for unmodify algorithm:"<<endl;
	for_each(v.begin(),v.end(),[](int i){
				cout<<i*i<<",";
			});
	cout<<endl;
	cout<<"the vector is:"<<endl;
	output(v);
	cout<<endl;
	cout<<"for_each use for modify algorithm"<<endl;
	for_each(v.begin(),v.end(),[](int& i){
				i=i*i;
			});
	output(v);
	cout<<endl;
	return 0;
}

