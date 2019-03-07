#include <iostream>
#include <thread>
#include <mutex>
#include <vector> 
#include <condition_variable>
using namespace std;

vector<int> v;
mutex m;
condition_variable cond;

void inputElements(int i){
	unique_lock<mutex> ul(m);
	cout<<"送进去了"<<i<<endl;
	v.push_back(i);
	cond.notify_one();
}

void getElement(){
	unique_lock<mutex> ul(m);
	cond.wait(ul,[](){
				return !v.empty();
			});
	while(!v.empty()){
		cout<<"取出"<<v.back()<<endl;
		v.pop_back();
	}
}

int main(){
	vector<thread> tv;
	for(int i=0;i<50;i++)
		tv.push_back(thread(inputElements,i));
	tv.push_back(thread(getElement));
	for(auto i=tv.begin();i!=tv.end();i++)
		i->join();
	return 0;
}
