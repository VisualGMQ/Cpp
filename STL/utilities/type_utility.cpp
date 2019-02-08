#include <iostream>
#include <type_traits>
using namespace std;

void say(){
	cout<<"hello"<<endl;
}

class test{
public:
	int a;
	void b();
};

int main(){
	cout<<"-----------------type_trait & type_utility--------------"<<endl;
	cout<<"you can use type_trait to judge a type,the template tmp must be a type,not a var!"<<endl;
	cout<<"type traits have a static member 'value' to return true or false.Or you can compare type_traits to true_type,false_type"<<endl;
	cout<<"is_void<int>:"<<is_void<int>::value<<endl
		<<"is_integral<int>:"<<is_integral<int>::value<<endl
		<<"is_signed<int>:"<<is_signed<int>::value<<endl
		<<"is_const<const int>:"<<is_const<const int>::value<<endl
		<<"is_volatile<int>:"<<is_volatile<int>::value<<endl
		<<"is_array<int[]>:"<<is_array<int[]>::value<<endl
		<<"is_enum<double>:"<<is_enum<double>::value<<endl
		<<"is_class<exception>:"<<is_class<exception>::value<<endl
		<<"is_function<decltype(say)>"<<is_function<decltype(say)>::value<<endl
		<<"is_reference<int&>:"<<is_reference<int&>::value<<endl
		<<"is_union<double>:"<<is_union<double>::value<<endl
		<<"is_pointer<int*>:"<<is_pointer<int*>::value<<endl
		<<"there are many other type traits"<<endl;

	cout<<"****type traits for class****"<<endl
		<<"there some type traits for class specially"<<endl;
	cout<<"is_empty<test>"<<is_empty<test>::value<<endl
		<<"is_polymorphic<test> (test will have a virtual member function at least):"<<is_polymorphic<test>::value<<endl
		<<"is_abstract<test>:"<<is_abstract<test>::value<<endl
		<<"is_default_constructible<test> (test have default constructor):"<<is_default_constructible<test>::value<<endl
		<<"there are many other traits"<<endl;
	cout<<"****there are some traits use to compare two type******"<<endl
		<<"is_same<int,unsigned int>:"<<is_same<int,unsigned int>::value<<endl
		<<"is_base_of<int,unsigned int>:"<<is_base_of<int,unsigned int>::value<<endl
		<<"is_convertible<int,float>:"<<is_convertible<int,float>::value<<endl
		<<"and many other traits"<<endl;
	cout<<"****there are some traits allow you add type to other type****"<<endl
		<<"you will use the static member 'type' to get the generate type"<<endl
		<<"you can use add_const<int>::type to get type 'const int'"<<endl
		<<"you can also use make_signed<unsigned int>::type to get type int"<<endl
		<<"like above,you can generate whatever you want"<<endl;

}
