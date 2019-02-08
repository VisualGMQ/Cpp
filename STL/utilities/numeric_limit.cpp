#include <iostream>
#include <exception>
#include <limits>
using namespace std;

int main(){
	cout.setf(ios_base::boolalpha);
	cout<<"-----------------numeric limits--------------"<<endl;
	cout<<"use numeric_limits<> to get information of numbers.And include 'limits'"<<endl;
	cout<<"numeric_limits<> is a static template class so that you shouldn't generate a object!"<<endl;
	cout<<"max of int(numeric_limits<int>::max()):"<<numeric_limits<int>::max()<<endl
		<<"min of int:"<<numeric_limits<int>::min()<<endl
		<<"is type int have limit?"<<numeric_limits<int>::is_specialized<<endl
		<<"is type int have sign?"<<numeric_limits<int>::is_signed<<endl
		<<"is type unsigned int have sign?"<<numeric_limits<int>::is_signed<<endl
		<<"is type float is integer?"<<numeric_limits<float>::is_integer<<endl
		<<"there are many other attributes and method about numeric limits"<<endl;
}
