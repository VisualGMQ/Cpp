#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
	ofstream of;
	of.open("test.txt");
	if(!of.is_open())
		cerr<<"the file is not open!";	
	cout<<"please input your text:";
	char str;
	while(!cin.fail()){
		cin.get(str);
		of<<str;	
	}
	of.close();
	return 0;	
}
