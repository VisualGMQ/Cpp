#include <iostream>
#include <iomanip>
using namespace std;

template <typename charT,typename traits>
inline basic_ostream<charT,traits>& split(basic_ostream<charT,traits>& o){
	int i=20;
	while(i--)
		o.put('-');
	o.put('\n');
	return o;
}

class split2{
private:
	char c;
public:
	split2(char c):c(c){};
	char getc(){
		return c;
	}
	friend ostream& operator<<(ostream& o,split2 sp);
};

ostream& operator<<(ostream& o,split2 sp){
	int i=20;
	while(i--)
		o.put(sp.getc());
	o.put('\n');
	return o;
}

int main(){
	float pi=3.14159;
	cout<<"set width:the pi is:"<<setw(10)<<pi<<endl;	
	cout<<"set boolalpha:"<<boolalpha<<true<<endl;
	int decimal=2333;
	cout<<"2333 in hex:"<<hex<<decimal<<endl
		<<"     in decimal:"<<dec<<decimal<<endl
		<<"     in oct:"<<oct<<decimal<<endl<<dec;
	cout<<"showbase:"<<showbase<<pi<<endl
		<<"fixed float:"<<fixed<<pi<<endl
		<<"scientific:"<<scientific<<pi<<endl
		<<"hexfloat:"<<hexfloat<<pi<<endl
		<<"noshowpoint:"<<noshowpoint<<pi<<endl
		<<"left:"<<setfill('_')<<left<<decimal<<endl
		<<"right:"<<setfill('_')<<right<<decimal<<endl
		<<"internal:"<<setfill('_')<<internal<<decimal<<endl
		<<fixed<<"setprecision(10):"<<setprecision(10)<<pi<<endl
		<<"user define manipulator:"<<split
		<<"user define manipulator2:"<<split2('*');
}
