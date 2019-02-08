#include <iostream>
#include <queue>
#include <ctime>
#include <random>
using namespace std;

int main(){
	priority_queue<int> pq;
	srand(time(nullptr));
	for(int i=0;i<=10;i++)
		pq.push(rand()/1000000);
	cout<<"pq.empty():"<<pq.empty()<<endl;
	cout<<"pq.size():"<<pq.size()<<endl;
	cout<<"pq.top():"<<pq.top()<<endl;
	pq.pop();
	cout<<"pq.top():"<<pq.top()<<endl;	
	pq.pop();
	cout<<"pq.top():"<<pq.top()<<endl;
}
