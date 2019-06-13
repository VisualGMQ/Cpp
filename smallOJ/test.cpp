#include <iostream>
//#define __DEBUG__
using namespace std;

int main(){
	int num;
	cin>>num;
	int bit[4] = {
		0
	};
	for(int i = 0;i<4;i++){
		bit[i] = num%10;
		#ifdef __DEBUG__
		cout<<bit[i];
		#endif
		bit[i]+=5;
		bit[i]%=10;
		num/=10;
	}
	int result = bit[0]*1000+bit[1]*100+bit[2]*10+bit[3];
	#ifdef __DEBUG__
	;
	#endif
	cout<<result;
	return 0;
}
