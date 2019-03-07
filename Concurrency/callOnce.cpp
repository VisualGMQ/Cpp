#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
mutex m;
once_flag call_flag;

void print(){
	cout<<"第一个线程开始了"<<endl;
}

void threadPrint(int i){
	lock_guard<mutex> lg(m);
	call_once(call_flag,print);
	cout<<"我是第"<<i<<"个线程"<<endl;
}

int main(){
	vector<thread> v;
	for(int i=0;i<10;i++)
		v.push_back(thread(threadPrint,i));
	for(int i=0;i<10;i++)
		v[i].join();
	return 0;
}
