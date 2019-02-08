#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	for(int i=0;i<10;i+=2){
		s.push(i);
		cout<<"push 0,2,4,6,8 in s"<<endl;
	}
	cout<<"the top element of s:"<<s.top()<<endl;
	cout<<"the size of s:"<<s.size()<<endl;
	cout<<"is s empty:"<<s.empty()<<endl;
	cout<<"the operates of stack is simple and eazy"<<endl
		<<"* push() push a element in stack"<<endl
		<<"* top() get the top element in stack,but not delete it"<<endl
		<<"* pop() delete the top element but not return it(the funtion is 'void')"<<endl;
}
