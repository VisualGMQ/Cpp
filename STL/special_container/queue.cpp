#include <iostream>
#include <queue>
using namespace std;

int main(){
	queue<int> q;
	for(int i=0;i<10;i+=2)
		q.push(i);
	cout<<"push 0,2,4,6,8 in q"<<endl;
	cout<<"q.front():"<<q.front()<<endl;	
	cout<<"q.back():"<<q.back()<<endl;
	cout<<"q.size():"<<q.size()<<endl;
	cout<<"q.empty():"<<q.empty()<<endl;
	cout<<"the same as stack,use pop() to delete the top element of q"<<endl;
}

