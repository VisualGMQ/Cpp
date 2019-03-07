#include <iostream>
#define MallocInt(name,value) \
int name=value;\
std::cout<<#name<<" is "<<name<<endl;

#define printstring(str) std::cout<<#str<<endl;
#define combinestr(a,b) a##b
using namespace std;

void say(){
	cout<<"the current function is "<<__FUNCTION__<<endl;
}

int main(){
	cout<<"当前文件名称:"<<__FILE__<<endl;	
	cout<<"当前执行到第几行:"<<__LINE__<<endl;
	cout<<"编译的时间是:"<<__DATE__<<endl;
	cout<<"编译的日期是:"<<__TIME__<<endl;
	say();
	printstring("hahha");
	int combinestr(hah,123)=0;
	MallocInt(hallow,10)
	return 0;
}
