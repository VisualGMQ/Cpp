#include <bitset>
#include <iostream>
using namespace std;

int main(){
	bitset<4> bs;
	cout<<"using .set() to set all bits to 1:"<<bs.set()<<endl
		<<"using .set(pos,value) to set pointed bit value:"<<bs.set(2,0)<<endl
		<<"using .set(pos) to set pointed bit 1:"<<bs.set(2)<<endl;
	bitset<8> bs2(0xf4);
	cout<<"print bs2:";
	for(int i=0;i<bs2.size();i++)
		cout<<bs2.test(i);
	cout<<endl;
	cout<<"flip the bs2:"<<bs2.flip()<<endl;	
	cout<<"bs2 to string:"<<bs2.to_string()<<endl;
	cout<<"bs2 to long:"<<bs2.to_ulong()<<endl;	
	cout<<"is any bit set:"<<bs2.any()<<endl;
	cout<<"is no bit set:"<<bs2.none()<<endl;
	cout<<"is all bit seted:"<<bs2.all()<<endl;

}
