#include <iostream>
#include <fstream>
#include <complex>
#include <sstream>
#include <string>
using namespace std;

ostream& operator<<(ostream& os,const complex<float> cp){
	os<<"the real is:"<<cp.real()<<" and the image is:"<<cp.imag();
	return os;
}

int main(){
	ostringstream os;
	os<<"the number is:"<<1235<<endl;	
	cout<<os.str()<<endl;
	istringstream is("this number is 12349");
	string str;
	int a;
	is>>str>>a;
	cout<<str<<a<<endl;
	complex<float> cp(1,3);
	os<<cp<<endl;
	cout<<os.str();
	cout<<"--------redirect ostream to ofstream--------"<<endl;
	cout<<"write some text in textbuf.txt"<<endl;
	streambuf* coutbuf = cout.rdbuf();
	ofstream of("testbuf.txt",ios::trunc);
	cout.rdbuf(of.rdbuf());
	cout<<"I have writed some text in textbuf.txt using cout"<<endl;
	of.close();
	cout.rdbuf(coutbuf);
}
