#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

vector<int> v;
mutex m1,m2;

void insert(int i){
	lock(m1,m2);
	cout<<"insert into v"<<endl;
	v.push_back(i);
	m2.unlock();
	m1.unlock();
}

void getElement(){
	lock(m1,m2);
	cout<<"get element in v"<<endl;
	if(!v.empty()){
		cout<<v.back()<<endl;
		v.pop_back();
	}
	m1.unlock();
	m2.unlock();
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
