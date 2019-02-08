#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	cout<<"************submat*************"<<endl;
	cout<<"------------mat---------------"<<endl;
	mat m(4,4,fill::randn);
	m.print("m:");
	m.col(2).print("m.col(2):");
	m.row(2).print("m.row(2)");
	m.cols(0,2).print("m.cols(0,2)");
	m.submat(1,1,2,2).print("m.submat(1,1,2,2)");
	m(0,0,size(2,2)).print("m(0,0,size(2,2)):");
	m.head_rows(2).print("m.head_rows(2):");
	m.tail_rows(3).print("m.tail_rows(3):");
	cout<<"---------vector----------"<<endl;
	vec v(5,fill::randn);
	v.print("v:");
	v.subvec(1,3).print("v.subvec(1,3):");
	v.head(2).print("v.head(2):");
	v.tail(3).print("v.tail(3):");
	cout<<"***********subcube***************"<<endl;
	cube cb(3,3,3,fill::randn);
	cb.print("cb:");
	cb.rows(0,1).print("cb.rows(0,1):");
	cb.slice(2).print("cb.slice(2):");
	cb.slices(0,1).print("cv.slices(0,1):");
	cb.subcube(1,1,0,2,2,1).print("cb.subcube(1,1,2,2,0,1):");
	cb.tube(0,1,0,1).print("cb.tube(0,1,0,1)");
	cout<<"***********subfield***************"<<endl;
	cout<<"field has same funtion as cube and mat:"<<endl
		<<".row() .rows() .col() .cols()"<<endl
		<<".subfields()"<<endl
		<<".slice() .slices()"<<endl;
}
