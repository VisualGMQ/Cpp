#include <armadillo>
#include <iostream>
using namespace std;
using namespace arma;

int main(){
	cout<<"-----------how to fill a mat/vec/row/cube/spMat---------"<<endl;
	mat m;
	m.zeros(3,3);
	m.print("m.zeros(3,3):");
	m.eye(3,3);
	m.print("m.eye(3,3):");
	m.ones(2,2);
	m.print("m.ones(2,2):");
	m.randu(4,4);
	m.print("m.randu(4,4):");	
	m.fill(-1);
	m.print("m.fill(-1):");
	m.imbue([](){static int i=0;
			return ++i;});
	m.print("m.imbue(lambda):");
	cout<<"-----------change elements--------------"<<endl;
	m.eye();
	m.print("m:");
	m.replace(1,2);
	m.print("replace 1 to 2:");
	m.transform([](mat::elem_type i){return i+2;});
	m.print("m.transform(lambda):");
	m.for_each([](mat::elem_type& i){i*=3;});
	m.print("m.for_each(lambda)");
}
