#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(){
	vector<int> v={1,2,3,4,5,6,7,8,9,10};
	cout<<"using numeric algorithm should #include <numeric> !!! "<<endl;
	cout<<"v:";
	for(int i:v)
		cout<<i<<" ";
	cout<<endl;	
	cout<<"sum of v:"<<accumulate(v.begin(),v.end(),0)<<endl;
	cout<<"sum of elements*2 in v:"<<accumulate(v.begin(),v.end(),0,[](const int initvalue,const int ele){return initvalue+ele*2;})<<endl;
	vector<int> v2={4,2,1,5,2,1,9,0,8,10};
	cout<<"v1 innner product v2:"<<inner_product(v.begin(),v.end(),v2.begin(),0)<<endl;
}
