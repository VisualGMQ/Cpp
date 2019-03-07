#include <iostream>
#include <future>
#include <thread>
using namespace std;

int getElement(){
	return 3;
}

void getResult(shared_future<int> f){
	cout<<"the result is:"<<f.get()<<endl;
}

int main(){
	future<int> result = async(launch::async,getElement);
	shared_future<int> s_result(result.share());
	thread t1(getResult,s_result);
	thread t2(getResult,s_result);
	thread t3(getResult,s_result);
	thread t4(getResult,s_result);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}
