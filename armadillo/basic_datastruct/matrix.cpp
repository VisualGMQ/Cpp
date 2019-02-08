#include <armadillo>
#include <iostream>
using namespace std;
using namespace arma;

int main(){
	cout<<"-----matrix------"<<endl;
	mat m1(4,4,fill::ones);
	cout<<"mat:"<<endl<<m1<<endl;	
	imat m2(4,4,fill::eye);
	cout<<"imat:"<<endl<<m2<<endl;
	cx_mat m3(4,4,fill::randu);
	cout<<"cx_mat:"<<endl<<m3<<endl;
	imat m4({{1,2,3},{4,5,6},{7,8,9}});
	cout<<"imat(initialize):"<<endl<<m4<<endl;
	m1.set_size(3,3);
	cout<<"change m1's size:"<<endl<<m1<<endl;
	m2.print("using m2.print():");
	imat::fixed<4,4> fixm({{1,2,3,4},{4,5,6,7},{7,8,9,0},{11,12,13,14}});
	fixm.print("fixed matrix:");
	m1.fill(2.333);
	m1.print("filled m1 with 2.333");
	
	cout<<endl<<"------Col&Row------"<<endl;
	cout<<"vec==colvec==dcolvec"<<endl<<"rowvec==drowvec"<<endl;
	cout<<"vec&rowvec is inherite from mat!"<<endl;
	vec v1(5,fill::randn);
	v1.print("vec:");
	vec::fixed<4> fixv(fill::eye);
	fixv.print("fixed vec:");
	rowvec rvec(3,fill::randn);
	rvec.print("rowvec:");
	cout<<endl<<"---------Cube--------"<<endl;
	cube cb(3,3,3,fill::randu);
	cb.print("cube(3,3,3):");
	cout<<endl<<"-------matrix->col&row--------"<<endl;
	m3.col(2).print("m3.col(2):");
	m3.row(2).print("m3.row(2):");
	cout<<endl<<"---------cube->matrix---------"<<endl;
	cb.slice(1).print("cube.slice(1)");
	cb.save("cbdata");
	cout<<"--------field--------"<<endl<<"field is a container to contain mat,vector,row ,cube...";
	mat m00(3,3,fill::zeros),m01(4,4,fill::randn),m10(5,5,fill::randu),m11(2,2,fill::eye);
	field<mat> f(2,2);
	f(0,0)=m00;
	f(0,1)=m01;
	f(1,0)=m10;
	f(1,1)=m11;
	f.print("field(2,2):");
	cout<<"---------SpMat--------"<<endl;
	sp_mat spmat(100,100);
	spmat.print("spare mat:");
	cout<<"---------operator in mat and generate class--------"<<endl;
	mat om1(3,3,fill::randu),om2(3,3,fill::randu);
	om1.print("om1:");
	om2.print("om2:");
	(om1+om2).print("om1+om2:");
	(om1-om2).print("om1-om2");
	(om1*om2).print("om1*om2");
	(om1%om2).print("om1%om2");	
	(om1==om2).print("get elements in om1==om2:");
	(om1>om2).print("get elements in om1>om2:");
}
