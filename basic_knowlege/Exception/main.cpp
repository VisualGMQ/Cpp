#include <iostream>
#include <exception>
#include <string>

using namespace std;
int main(){
	int input;
	cout<<"1:abort()"<<endl
		<<"2:throw a string"<<endl
		<<"3:throw a std::exception"<<endl;
	cin>>input;
	switch(input){
		case 1:
			abort();
			break;
		case 2:
			try{
				throw "caugth error! this is a string";
			}catch(const char* str){ //需要注意的是这里不可以catch string。移位string是个类，需要throw string类才可以捕获到。通常的字符串被视为C字符串。
				cout<<str<<endl;
			}
			break;
		case 3:
			try{
				throw exception();
			}catch(exception& e){
				cout<<e.what()<<endl;
			}
			break;
	}
}
