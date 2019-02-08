#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	string str1("hello"),str2("hello",7),str3(5,'h');
	cout<<"str1(\"hello\"):"<<str1<<" "<<str1.length()<<endl;	
	cout<<"str2(\"hello\",7):"<<str2<<" "<<str2.length()<<endl;	
	cout<<"str3(5,'h'):"<<str3<<" "<<str3.length()<<endl;	
	cout<<"can not give single char to init a string."
		<<"but you can init the string as 'string({'a'});' or 'string(1,'a');'"<<endl;
	cout<<"the length of str1.c_str():"<<sizeof(str1.c_str())/sizeof(str1.c_str()[0])<<endl;
	cout<<"-----------size of string---------"<<endl;
	cout<<"str1.size():"<<str1.size()<<endl;
	cout<<"str1.max_size():"<<str1.max_size()<<endl;
	cout<<"str1.capacity():"<<str1.capacity()<<endl;
	cout<<"str1.shrink_to_fit()"<<endl;
	str1.shrink_to_fit();
	cout<<"str1.size():"<<str1.size()<<endl;
	cout<<"str1.max_size():"<<str1.max_size()<<endl;
	cout<<"str1.capacity():"<<str1.capacity()<<endl;
	
	cout<<"-------------visite elements---------"<<endl;
	cout<<"str1[2]:"<<str1[2]<<endl
		<<"str1.at(2):"<<str1.at(2)<<endl
		<<"str1.front():"<<str1.front()<<endl
		<<"str1.back():"<<str1.back()<<endl;
	cout<<"-------------comparision-------------"<<endl;
	cout<<"str1>str2:"<< (str1>str2) <<endl
		<<"str1.compare(str2):"<<str1.compare(str2)<<endl
		<<"str1.compare(0,3,str2,0,2):"<<str1.compare(0,3,str2,0,2)<<endl;
	cout<<"--------------assignment--------------"<<endl;
	cout<<"using = is ok"<<endl;
	cout<<"-------------swap-------------------"<<endl;
	cout<<"using swap() or .swap() is ok"<<endl;
	cout<<"----------------let string be empty-------------"<<endl;
	cout<<"str1=\"\" or str1.clear() or str1.erase(),str1:";
	str1.clear();
	cout<<str1<<endl;
	cout<<"-----------------insert and remove--------------"<<endl;
	str1+="haha";
	cout<<"using += is ok:"<<str1<<endl;
	str1.append("6123");
	cout<<"str1.append(\"6123\"):"<<str1<<endl;
	str1.append(4,'x');
	cout<<"str1.append(4,'x'):"<<str1<<endl;
	str1.insert(2,"VisuaGMQ");
	cout<<"str1.insert(2,\"VisualGMQ\"):"<<str1<<endl;
	str1.push_back('e');
	cout<<"str1.push_back(\"end\"):"<<str1<<endl;
	str1.replace(0,5,"replaced");
	cout<<"str1.replace(0,5,\"replaced\"):"<<str1<<endl;
	str1.erase(4,8);
	cout<<"str1.erase(4,8):"<<str1<<endl;
	str1.pop_back();
	cout<<"str1.pop_back():"<<str1<<endl;
	cout<<"---------------io operator----------------"<<endl;
	cout<<"<< and >> is ok"<<endl;
	cout<<"using getline() to get a line from input(please input):";
	getline(cin,str1);
	cout<<"you inputed "<<str1<<endl;
	cout<<"---------------search--------------"<<endl;
	string s="My name is VisualGMQ,his name is XXX";
	cout<<"s:"<<s<<endl;
	string::size_type idx;
	idx=s.find("name");
	cout<<"find 'name':"<<idx<<endl;
	idx=s.rfind("name");
	cout<<"rfind 'name':"<<idx<<endl;
	idx=s.find_first_not_of("My name");
	cout<<"find_first_not_of(\"My name\"):"<<idx<<endl;
	idx=s.find("asdawfa");
	cout<<"find a substring not exists:"<<idx<<" this is string::npos"<<endl;
	cout<<"--------------convert string and numeric------------"<<endl;
	s="1471289";
	cout<<"s:"<<s<<endl;
	cout<<"stoi(s) (string to int):"<<stoi(s)<<endl;
	cout<<"stoi(\"0xfa\"):"<<stoi("0xfa")<<endl;
	cout<<"convert hex to decimal:stoi(\"123\",nullptr,16)"<<stoi("123",nullptr,16)<<endl;
	cout<<"stol(s) (string to long):"<<stol(s)<<endl;
	cout<<"also has stoul(string to unsihned long)\nstoll(string to long long)\nstoull(string to unsigned long long)\nstof(string to float)\nstod(string to double)\nstold"<<endl;
	cout<<"to_string(123).length():"<<to_string(123).length()<<endl;
	cout<<"--------------------iterator-----------------"<<endl;
	cout<<".begin() .end() .rbegin() .rend() .append() .assign() .insert() .erase(0 .replace()"<<endl;
}
