#include <iostream>
#include <functional>
#include <random>
#include <algorithm>
#include <vector>
#include <numeric>
#include <numeric>
#include <string>
using namespace std;
using namespace placeholders;

void print(const string msg,const vector<int>& v){
	cout<<msg;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	vector<int> v(10);
	iota(v.begin(),v.end(),1);	
	print("v:",v);
	reverse(v.begin(),v.end());
	print("revers v:",v);
	cout<<"revers_copy() will not display"<<endl;
	rotate(v.begin(),v.begin()+3,v.end());
	print("rotate v(point is v[3]):",v);
	cout<<"rotate_copy() will not display"<<endl;
	next_permutation(v.begin(),v.end());
	print("next_permutation v:",v);
	default_random_engine dre;
	shuffle(v.begin(),v.end(),dre);
	print("shuffle v:",v);	
	partition(v.begin(),v.end(),bind(greater<int>(),_1,4));	
	print("partition elements > 4 in v:",v);
	shuffle(v.begin(),v.end(),dre);
	print("shuffled v:",v);
	stable_partition(v.begin(),v.end(),bind(greater<int>(),_1,4));	
	print("stable partition:",v);

	vector<int> vpv1(10),vpv2(10);
	partition_copy(v.begin(),v.end(),vpv1.begin(),vpv2.begin(),[](const int& i){return i>5;});
	cout<<"partiotn_copy the v into vpv1,vpv2:"<<endl;
	print("vpv1:",vpv1);
	print("vpv2:",vpv2);


}
