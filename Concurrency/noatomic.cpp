#include <iostream>
#include <thread>
#include <future>
#include <ctime>
using namespace std;

int data;
long t = 0;
mutex m;
void writeData(){
	for(int i=0;i<50000000;i++){
		m.lock();
		data++;
		m.unlock();
	}
}

int main(){
	t = time(nullptr);
	thread t1(writeData);
	thread t2(writeData);
	thread t3(writeData);
	thread t4(writeData);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t = time(nullptr) - t;
	cout<<"the i is:"<<data<<endl;
	cout<<"passed "<<t<<"s"<<endl;
	return 0;
}
