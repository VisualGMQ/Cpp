#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	cout<<"the functions below only using on mat,vec and cube!!!"<<endl;
	imat m(4,4,fill::randn);
	m.print("m:");		
	abs(m).print("abs(m):");
	cout<<"accu(m):"<<accu(m)<<endl;
	ivec v(3,fill::randn);
	v.insert_rows(2,1);
	v(3)=1;
	cout<<m<<"*"<<v<<"=";
	v.shed_row(3);
	cout<<affmul(m,v)<<endl;
	cout<<"is m has zero element:"<<all(m)<<endl;
	cout<<"is m has elements<-1:"<<all(m<-1)<<endl;	
	cout<<"is any element>0:"<<any(m>0)<<endl;
	clamp(m,-2,0).print("clamp a mat elements between -2,0:");
	conj(m).print("get the conjunction of m:");
	conv_to<mat>::from(m).print("convert int_mat to float_mat");
	irowvec v1("1,2,3"),v2("4,5,6");
	v1.print("v1:");
	v2.print("v2:");
	cross(v1,v2).print("the cross of v1&v2:");
	cumsum(v1).print("the cumsum of v1:");
	cumsum(m).print("the cumsum of m:");
	cumprod(v1).print("the cumprod of v1:");
	cumprod(m).print("the cumpord of m:");
	cout<<"m is square:"<<m.is_square()<<endl;
	cout<<"m's det:"<<det(conv_to<mat>::from(m))<<endl;
	cout<<"the det() only effect on double_mat and float_mat!!!"<<endl;
}
