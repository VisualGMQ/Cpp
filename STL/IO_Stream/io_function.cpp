#include <iostream>
#include <string>
using namespace std;

int main(){
	cout<<"Manupulators:"<<endl;
	cout<<"endl:"<<endl;
	cout<<"ends:"<<ends;
	cout<<"flush:"<<flush;	
	cout<<endl<<"all flags will throw exception:"<<cout.exceptions()<<endl;
	cout<<"-----------------some input output function--------------"<<endl;
	cout.put('a');
	cout.put('\n');
	cout<<"please input a string:";
	char str[100];
	cin.get(str,10);
	cout<<"the app will only read in 10 char:"<<str<<endl;
	cout<<"please input a string and we will read it util meet 'E':";
	cin.get(str,100,'E');
	cout<<"the str is:"<<str<<endl;
	cout<<"please input a string and we will read \\n also:";
	cin.getline(str,100,'\n');
	cout<<"the str is:"<<str;
	cout<<"using read() to read 20 chars:";
	cin.read(str,20);
	cout<<"str is:"<<str<<endl;
	cout<<"please input a string and we will ignore 5 chars:";
	cin.ignore(5);
	cin.getline(str,100);
	cout<<"str is:"<<str<<endl;
	string str2="wirte some string!";
	cout.write(str2.c_str(),str2.size());

}
