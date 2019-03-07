#include <iostream>
#include <thread>
#include <future>
using namespace std;

void setValue(promise<int> pro){
	pro.set_value(10);
}
void printValue(future<int> pro){
	cout<<"the value is:"<<pro.get()<<endl;
}

int main(){
	promise<int> data;
	future<int> result = data.get_future();
	thread th1(setValue,move(data));
	thread th2(printValue,move(result));
	th1.join();
	th2.join();
	return 0;
}
