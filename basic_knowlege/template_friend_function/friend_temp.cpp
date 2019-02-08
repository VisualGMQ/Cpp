#include <iostream>
using namespace std;

template <typename T>
class test{
public:
	test(T data):info(data){};
	T get(){return info;}
	friend ostream& operator<<(ostream& os,test<T>& t);
private:
	T info;
};

template <typename T>
ostream& operator<<(ostream& os,test<T>& t){
	os<<t.get()<<endl;
}

int main(){
	test<int> t(10);
	cout<<t;
}
