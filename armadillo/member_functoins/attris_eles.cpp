#include <armadillo>
#include <iostream>
using namespace std;
using namespace arma;

int main(){
	cout<<"----------attributes-------------"<<endl;
	mat m(4,4,fill::randu);
	m.print("m:");
	cout<<"m's col&row:"<<m.n_cols<<","<<m.n_rows<<endl;
	cout<<"m's total element number:"<<m.n_elem<<endl;
	cube cb(3,3,2,fill::randu);	
	cb.print("cube:");
	cout<<"cube slice number:"<<cb.n_slices<<endl;
	sp_mat spm(100,100);
	cout<<"spm:"<<endl;
	cout<<spm;
	cout<<"not zero element in spare mat:"<<spm.n_nonzero<<endl;
	cout<<"------------elements access-----------"<<endl;
	vec v(5,fill::randu);
	v.print("vec:");
	cout<<"for vec,use (n) to get element [v(3)]:"<<v(3)<<endl;
	cout<<"for mat,use (i,j) to get element [m(2,3)]:"<<m(2,3)<<endl;
	cout<<"for cube and 3D field,use (i,j,k) to get a element [cb(2,2,1)]:"<<cb(2,2,0)<<endl
	    <<"or use (n) to get a slice:"<<endl<<cb(0)<<endl;
}
