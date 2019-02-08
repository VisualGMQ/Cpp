#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
	vector<int> v={1,2,3,4,5,6,7},mv(7);
	ostream_iterator<int> o(cout," ");
	cout<<"v:";
	copy(v.begin(),v.end(),o);
	move(v.begin(),v.end(),mv.begin());
	cout<<"move v to mv"<<endl;
	cout<<"v:";
	copy(v.begin(),v.end(),o);
	cout<<endl<<"mv:";
	copy(mv.begin(),mv.end(),o);
	cout<<endl;	
	cout<<"move backward to mv"<<endl;
	move_backward(v.begin(),v.end(),mv.end());
	cout<<"v:";
	copy(v.begin(),v.end(),o);
	cout<<endl<<"mv:";
	copy(mv.begin(),mv.end(),o);
	cout<<endl;	
}
