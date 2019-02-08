#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	vec v({1,2,3,4,5});
	mat m({{1,2,3},{4,5,6},{7,8,9}});
	v.print("v:");
	m.print("m:");
	cout<<"the mean of v:"<<mean(v)<<endl;
	mean(m).print("the mean of m:");
	cout<<"the median of v:"<<median(v)<<endl;
	median(m).print("median of m:");
	cout<<"standrad deviation of v:"<<stddev(v)<<endl;
	stddev(m).print("standrad deviation of m:");
	cout<<"variance of v:"<<var(v)<<endl;
	var(m).print("variance of m:");
	cout<<"the difference between max and min of v:"<<range(v)<<endl;
	range(m).print("the difference between max and min of m:");
	cout<<"the cov of v:"<<cov(v)<<endl;
	cout<<"the correlation of v:"<<cor(v)<<endl;
}
