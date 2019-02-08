#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main(){
	eye<mat>(4,4).print("using eye<T>() function to generate a mat:");
	linspace<vec>(0,6).print("using linspace<T>() to generate a col_vec:");
	linspace<rowvec>(0,6,3).print("using linspace<T>() to generate a row_vec:");
	logspace<vec>(0,100).print("using logspace<T>() to generate a colvec:");
	regspace<vec>(0,5,50).print("using regspace<T>() to generate a vec:");
	ones<mat>(3,3).print("using ones<T>() to generate a mat:");
	randi<mat>(3,3).print("using randi<T>() to generate a mat:");
	cout<<"also has randu/randn/randg() function"<<endl;
	zeros<rowvec>(5).print("using zeros<T>() to generate a vec:");
	cout<<"also has spones/speye/sprandu/sprandn() to generate a spares mat"<<endl;	
	return 0;
}
