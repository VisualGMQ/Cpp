#include <iostream>
#include <random>
using namespace std;

int main(){
	cout<<"when you want to get a random number,you must have a radom engine and a distribution.The former give a number ,and the later give a way to mess the number"<<endl;
	default_random_engine dre;
	cout<<"generate 10 integers in [10,20]:";
	uniform_int_distribution<int> id(10,20);
	for(int i=0;i<10;i++)
		cout<<id(dre)<<" ";
	cout<<endl;
	cout<<"generate 10 floats in [10,20]:";
	uniform_real_distribution<float> fd(10,20);
	for(int i=0;i<10;i++)
		cout<<fd(dre)<<" ";
	cout<<endl;
	cout<<"every random engine will be same at initalization.So don't change the engine casually and use temp engine"<<endl;
	cout<<"if you send a seed to the engine,it will be different(but the seed must different too)"<<endl;
	default_random_engine dre2(40);
	cout<<"generate 10 integers in [10,20]:";
	for(int i=0;i<10;i++)
		cout<<id(dre2)<<" ";
	cout<<endl;
	cout<<"you can use .seed() to get or set a seed to an engin,use .discard(n) to discard next n elements,or use == != to compare two states of engine"<<endl;
	cout<<"there are many engine:linear_congruential_engine,mersenne_twister_engine and other"<<endl
		<<"and many distribution:uniform distribution,bernouli distribution,poisson distribution and other.They are represent at 《possibility》"<<endl;
}
