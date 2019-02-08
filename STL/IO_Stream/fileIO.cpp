#include <iostream>
#include <fstream>
using namespace std;

int main(){
	cout<<"in file io,if you use fstream to read and write,you can't switch the two states casually.An exception is when you read at EOF,you can write immediatly."<<endl;
	cout<<"Note:ostream is ready for write,istream is ready for read.File must be exists to read!"<<endl;
	fstream f("test.bin",ios::in);
	if(f.is_open()==false)
		cout<<"file not exists,create one"<<endl;
	f.close();
	f.open("test.bin",ios::out|ios::trunc);	
	cout<<"we will write a string you input:";
	char c;
	while((c=cin.get())!='q')
		f.put(c);
	f.close();
	f.clear();
	f.open("test.bin",ios::in);
	cout<<"the text in test.bin:"<<endl;
	cout<<f.rdbuf();
	cout<<endl;
	cout<<"jump to head to output again:"<<endl;
	f.seekp(0,ios::beg);
	cout<<f.rdbuf()<<endl;
	cout<<"move forward 10 char to output again:"<<endl;
	f.seekp(-10,ios::cur)<<endl;
	cout<<f.rdbuf()<<endl;
	f.close();
}
