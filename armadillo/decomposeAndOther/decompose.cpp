#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	imat m({{1,2,3},{4,5,6},{7,8,9}});
	m.print("m:");
	inv(conv_to<mat>::from(m)).print("the inverse of m:");
	mat l,u,p;
	lu(l,u,p,conv_to<mat>::from(m));
	cout<<"the lu decompose of m:"<<endl;
	l.print("l:");
	u.print("u:");
	p.print("p:");	
	mat q,r;
	qr(q,r,conv_to<mat>::from(m));
	cout<<"the qr decompose of m:"<<endl;
	q.print("q:");
	r.print("r:");
	vec b({1,2,3});
	b.print("b:");
	solve(conv_to<mat>::from(m),b).print("solve systems of linear of m and b:");
}
