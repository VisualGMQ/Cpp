#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	vector<int> v={1,2,3,4,5,6,7},cv(7);
	cout<<"v:\n";
	for_each(v.begin(),v.end(),[](const int i){cout<<i<<" ";});
	cout<<endl;
	copy(v.begin(),v.end(),cv.begin());
	cout<<"copy v to cv:"<<endl;
	cout<<"cv:";
	ostream_iterator<int> o(cout," ");
	copy(cv.begin(),cv.end(),o);
	cout<<endl;	
	cout<<"copy 3 elements to cv:";
	copy_n(v.rbegin(),3,cv.begin());
	copy(cv.begin(),cv.end(),o);
	cout<<endl;	
	cout<<"copy backward:";
	copy_backward(v.begin(),v.end(),cv.end()-3);
	copy(cv.begin(),cv.end(),o);
	cout<<endl;
}
