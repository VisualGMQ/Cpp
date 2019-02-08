#include <complex>
#include <iostream>
using namespace std;

int main(){
	cout<<"using complex<> to achieve complex number"<<endl;
	complex<int> c(1,2);
	cout<<"the complex is"<<c<<endl;
	cout<<"using polar system to define a complex number:"<<polar(2.,0.5)<<endl;
	cout<<"the real of c:"<<c.real()<<endl
		<<"the image of c:"<<c.imag()<<endl
		<<"the abs of c:"<<abs(c)<<endl
		<<"the normal of c:"<<norm(c)<<endl
		<<"the arg of c:"<<arg(c)<<endl
		<<"the conjuction of c:"<<conj(c)<<endl
		<<"the project of c:"<<proj(c)<<endl;
	cout<<"you can also use math function on complex:"<<endl
		<<"tan(c):"<<tan(c)<<endl
		<<"exp(c):"<<exp(c)<<endl;	
	
}
