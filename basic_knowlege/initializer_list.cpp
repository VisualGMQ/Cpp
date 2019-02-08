#include <iostream>
#include <initializer_list>

using namespace std;

void output(initializer_list<int[5]> const &init){
	for(auto i=init.begin();i!=init.end();i++){
		cout<<endl;
		for(int j=0;j<5;j++)
			cout<<(*i)[j]<<",";
	}
	cout<<endl;
		
}

int main(){
	output({{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}});
	return 0;
}
