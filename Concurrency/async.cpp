#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <future>
using namespace std;

int getNumber(){
	cout<<this_thread::get_id()<<" thread is start"<<endl;
	chrono::seconds sec(3);
	this_thread::sleep_for(sec);
	return 5;
}

int main(){
	cout<<this_thread::get_id()<<" Main thread is start"<<endl;
	future<int> future = async(launch::deferred,getNumber);
	//cout<<"the return value is:"<<future.get()<<endl;
	cout<<"Main thread end"<<endl;
	return 0;
}
