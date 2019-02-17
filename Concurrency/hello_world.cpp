#include <iostream>
#include <thread>
using namespace std;

void print(){
	cout<<"sub thread is begin"<<endl;
	cout<<"sub thread is end"<<endl;
}

int main(){
	thread th(print);
	th.detach();

	cout<<"Main thread is end"<<endl;
	return 0;
}
