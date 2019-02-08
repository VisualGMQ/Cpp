#include <iostream>
using namespace std;

enum Type{NONE,TYPE1,TYPE2};

class parent{
	public:
		parent():type(TYPE1){};
		parent(int data,int type):data(data),type(TYPE1){};
	protected:
		int data;
		Type type;
};

class children:public parent{
	public:
		children();
		children(int data,Type type);
};

children::children(){
	cout<<data<<','<<type<<endl;
}

int main(){
	children c;
	cout<<TYPE1<<endl;
	return 0;
}
