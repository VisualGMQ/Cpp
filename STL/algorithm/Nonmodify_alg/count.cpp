#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	vector<int> v={1,2,3,4,5,6,7};
	cout<<"the vector is:"<<endl;
	ostream_iterator<int> o(cout,",");
	copy(v.begin(),v.end(),o);
	cout<<endl;
	cout<<"how many elements equal to 5:"<<count(v.begin(),v.end(),5)<<endl;
	cout<<"how many elements between 2 to 6:"<<count_if(v.begin(),v.end(),[](const int i){
			return i>=2 && i<=6;
			})<<endl;
	return 0;
}
