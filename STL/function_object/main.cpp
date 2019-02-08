#include <iostream>
#include <functional>
#include <vector>
#include <iterator>
using namespace std;
using namespace std::placeholders;

//a function object
template <typename T>
class sum_rest{
public:
	sum_rest(T first):rest(first){}
	sum_rest():rest(0){}
	T operator()(T data1){
		return rest+=data1;
	}
private:
	T rest;
};

int main(int argc,char* argv[]){
	cout<<"define a function object which can sum up the data and last result:"<<endl;
	vector<int> v(10);
	generate_n(v.begin(),10,[](){
			static int i=0;
			return ++i;
			});
	cout<<"using sum_rest to sum up:"<<endl;
	sum_rest<int> rest;
	for(int i : v)
		cout<<rest(i)<<endl;
	cout<<"using system's funtion object negate<int>():"<<endl;
	for_each(v.begin(),v.end(),negate<int>());
	ostream_iterator<int> output(cout,","); 
	copy(v.begin(),v.end(),output);	
	cout<<endl;
	auto multi20 = bind(multiplies<int>(),_1,20);
	cout<<"using bind() to bind param to multiplies<>()"<<endl;
	for(auto i : v)
		cout<<multi20(i)<<",";
	cout<<endl;	
	return 0;
}
