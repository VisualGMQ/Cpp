#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	mat m(4,4,fill::randn);
	m.print("m:");
	m.diag().print("m.diag():");
	m.diag(1).print("m.diag(1):");
	m.diag(-1).print("m.diag(-1):");	
	m.each_row([](rowvec& row){row=row+2;});
	m.print("m.each_row(lambda):");
	cout<<"for cube and field,also have function .each_slice()"<<endl;
	cout<<"-----------------------------------"<<endl;
	cx_mat cxmat(3,3,fill::eye);
	cxmat.print("cxmat:");
	cxmat.insert_rows(1,cx_rowvec(3,fill::randn));
	cxmat.print("cxmat.insert_rows():");
	cxmat.shed_row(0);
	cxmat.print("cxmat.shd_row(0):");
	cxmat.swap_cols(0,2);
	cxmat.print("cxmat.swap(0,2):");
	cout<<"------------------------------------"<<endl;
	double* mptr = m.memptr();
	cout<<"using .memptr() to get memory pointer of m:";
	for(int i=0;i<16;i++)
		cout<<(*mptr)++<<" ";
	cout<<endl;
	mptr = m.colptr(2);
	cout<<"using .colptr() to get memory pointer of column of m:";
	for(int i=0;i<4;i++)
		cout<<(*mptr)++<<" ";
	cout<<endl;
	cout<<"in memory,elememts are ordered in column major"<<endl;
	cout<<"using iterator to get elements of m:(m.begin(),m.end()):";
	for(auto it=m.begin();it!=m.end();it++)
		cout<<*it<<" ";
	cout<<endl;
	cout<<"using col iterator ro get a column elements(m.begin_col(),m.end_col()):";
	for(auto it=m.begin_col(2);it!=m.end_col(2);it++)
		cout<<*it<<" ";
	cout<<endl;
	cout<<"--------------------------------------"<<endl;
	m.t().print("get transpose of m:");
	m.i().print("get inverse pf m:");
	cout<<"get min,max element of m:"<<m.min()<<","<<m.max()<<endl;
	cout<<"get min_index,max_index of m:"<<m.index_min()<<","<<m.index_max()<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"is row 5,col 5 valid:"<<m.in_range(5,5)<<endl;
	cout<<"is m empty:"<<m.is_empty()<<endl;
	cout<<"is m a vec:"<<m.is_vec()<<endl;
	cout<<"is m sorted:"<<m.is_sorted()<<endl;
	cout<<"is m a square matrix:"<<m.is_square()<<endl;
	cout<<"is m a symmetric matrix:"<<m.is_symmetric()<<endl;
	cout<<"is all elements of m is finite:"<<m.is_finite()<<endl;
	cout<<"is m has infinite element(s):"<<m.has_inf()<<endl;
	cout<<"is m has nan:"<<m.has_nan()<<endl;
	cout<<"---------------------------------------"<<endl;
	m.raw_print("raw_print m:");
	cout<<"---------------------------------------"<<endl<<"save m"<<endl;
	m.save("m_armaAscii.bin",arma_ascii);
	m.save("m_autoDetect.bin",auto_detect);
	m.save("m_rawAscii.bin",raw_ascii);
	m.save("m_csvAscii.bin",csv_ascii);
	cout<<"----------------------------------------"<<endl<<"load m"<<endl;
	m.load("m_armaAscii.bin",arma_ascii);
	m.print("loaded m:");
}
