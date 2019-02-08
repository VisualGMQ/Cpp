#include <iostream>
#include <ratio>
using namespace std;

int main(){
	cout<<"ratio<> template is a type using at compiling."<<endl;
	typedef ratio<30,12> a;
	cout<<"you can use typedef to define ratio,so you can use static member den and num to get denominator and mulecular"<<endl
		<<"a::den "<<a::den<<endl
		<<"a::num "<<a::num<<endl;
	ratio<30,13> b;
	cout<<"Or you can generate a object to use ratio,use .den .num to get infomations"<<endl
		<<"b.den:"<<b.den<<endl
		<<"b.num:"<<b.num<<endl;
	cout<<"there are also ratio_add<> ratio_subtract<> ratio_multiply<> ratio_divide<> to get math operation.And ratio_equal<> ratio_less<>... to compare two ratio.The static value return true or false,or type to get the return type"<<endl;
	cout<<"a+b:"<<ratio_add<a,decltype(b)>::den<<"/"<<ratio_add<a,decltype(b)>::num<<endl;
	cout<<"a==b:"<<ratio_equal<a,decltype(b)>::value<<endl;
	cout<<"there also some predeclared ratio type like yocto(1/10^24),centi(1/100),milli(1,1000),hecto(100),peta(10^15) and others"<<endl;
	cout<<"micro::den/micro::num:"<<micro::den<<"/"<<micro::num<<endl;
}
