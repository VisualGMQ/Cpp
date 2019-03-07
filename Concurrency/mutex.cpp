#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

vector<int> v;
mutex m;

void insert(int i){
	m.lock();   //lock
	cout<<"insert into v"<<endl;
	v.push_back(i);
	m.unlock(); //unlock
}

void getElement(){
	m.lock();   //lock
	cout<<"get element in v"<<endl;
	if(!v.empty()){
		cout<<v.back()<<endl;
		v.pop_back();
	}
	m.unlock(); //unlock
}


int main(){
	vector<thread> tv;
	for(int i=0;i<10;i++)
		tv.push_back(thread(insert,i));
	for(int i=0;i<10;i++)
		tv.push_back(thread(getElement));
	for(auto i=tv.begin();i!=tv.end();i++)
		i->join();
	return 0;
}
