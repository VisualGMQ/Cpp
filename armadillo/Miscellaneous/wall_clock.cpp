#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	wall_clock timer;
	timer.tic();
	cout<<"loop 100000 times"<<endl;
	for(int i=0;i<100000;i++);
	cout<<"measured the time:"<<timer.toc()<<endl;
}
