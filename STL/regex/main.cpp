#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
	string text="\
	《When you are old》\n\
	--- William Butler Yeats ——\n\
When you are old and grey and full of sleep,\n\
And nodding by the fire，take down this book,\n\
And slowly read,and dream of the soft look,\n\
Your eyes had once,and of their shadows deep,\n\
How many loved your moments of glad grace,\n\
And loved your beauty with love false or true,\n\
But one man loved the pilgrim Soul in you,\n\
And loved the sorrows of your changing face,\n\
And bending down beside the glowing bars,\n\
Murmur,a little sadly,how Love fled,\n\
And paced upon the mountains overhead,\n\
And hid his face amid a crowd of stars.\n\
		《Had I not seen the Sun》\n\
			—— Emily Dickinson\n";
	cout<<"----------------test text---------------"<<endl;
	cout<<text;
	cout<<"----------------------------------------"<<endl;
	regex reg1("and (.*)");
	cout<<"reg1:\"and (.*)\""<<endl;
	cout<<"regex_match() is finded:"<<regex_match(text,reg1)<<endl;
	cout<<"regex_search() is finded:"<<regex_search(text,reg1)<<endl;
	smatch m;
	regex_search(text,m,reg1);
	cout<<"result is:"<<endl;
	for(int i=1;i<m.size();i++)
		cout<<m[i].str()<<endl;	
	cout<<"m.prefix():"<<m.prefix()<<endl;
	cout<<"m.suffix():"<<m.suffix()<<endl;
	cout<<"m.size()"<<m.size()<<endl;
	cout<<"* smatch is a generation of match_results<string>.there are"<<endl
		<<"* cmatch-match_results<const char*>"<<endl
		<<"* wsmatch-match_results<wstring>"<<endl
		<<"* wcnatch-match_results<const wchar_t*>"<<endl;
	cout<<"* you can also use iterator to find and iter m"<<endl;
	sregex_iterator pos(text.cbegin(),text.cend(),reg1);
	cout<<"* there are sregex_iterator,cregex_iterator,wsregex_iterator,wcregex_iterator"<<endl;
	sregex_iterator end;
	for(;pos!=end;pos++)
		cout<<pos->str(1)<<endl;
	cout<<"replace all text match reg1 to ***$1"<<endl;
	cout<<regex_replace(text,reg1,"***$1")<<endl;
		
}
