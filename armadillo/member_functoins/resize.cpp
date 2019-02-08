#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	mat m(3,3,fill::randu);	
	m.print("m:");
	m.set_size(2,2);
	m.print("change size without keep element(fast)");
	m.reshape(4,4);
	m.print("change size keep element:");
	vec v(5,fill::ones);
	v.print("v:");
	m.copy_size(v);
	m.print("change size same as v:");
	m.reset();
	m.print("m.reset():");
}

