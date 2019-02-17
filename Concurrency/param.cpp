#include <iostream>
#include <thread>
using namespace std;

void print(int m){
	cout<<m<<endl;
}

int main(){
	int m=10;
	thread th(print,m);
	th.join();
	cout<<"Main thread is end"<<endl;
	return 0;
}
