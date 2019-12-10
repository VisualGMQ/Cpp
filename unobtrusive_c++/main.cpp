//这里面的特性，没有着重说明的均是C++11出现的特性
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//抛出已经废弃的警告。这样就可以在不删除旧的代码下提醒其他人了。官方说自C++14起。但是GNUC的编译器在C++11下也可以编译
//相应的还有noreturn，表示函数不会返回（这里的返回是指不会返回调用点，可能在函数末尾没有ret指令）。比如exti,abort这种都会声明为noreturn。并且如果noreturn的函数返回了，那么行为是未定的。可以拿来抑制一些警告
[[deprecated("this function is deprecated")]]
void say(){
    cout<<"hello c++14"<<endl;
}

class Person{
public:
    Person(string nname, float nheight):name(nname), height(nheight){}
    friend ostream& operator<<(ostream& o, Person& p);
private:
    string name;
    float height;
};

ostream& operator<<(ostream& o, Person& p){
    cout<<p.name<<"'s height is "<<p.height;
    return o;
}

struct sa{
    int i;
    double j;
    char k;
};

//使用alignas来改变对其的字节，现在对其的字节为16Bytes
//关于对其要求的详细说明看这里:https://zh.cppreference.com/w/cpp/language/object#.E5.AF.B9.E9.BD.90
struct alignas(16) sb{
    int i;
    double j;
    char k;
};

int main(int argc, char** argv){
    say();
    //原始字符串，里面的字符不会被转译。使用`R"(`  `)"`包括起来即可
    string raw_str = R"(this is a \n raw \t string \a)";
    cout<<raw_str<<endl;

    vector<int> v({1,2,3,4});
    //这里的for in循环和auto关键字也不是很常用。
    for(auto ele : v)
        cout<<ele<<endl;
    
    //可以像结构体一样，通过{}来调用构造函数。更加模糊了结构体和类之间的区别
    Person p = {"VisualGMQ", 20};
    cout<<p<<endl;

    //C++14新特性，在lambda表达式中都可以使用auto关键字了（本质上使用了模板）
    auto max = [](auto a, auto b){return a>b?a:b;};
    cout<<max(3, 5)<<endl;

    //alignof关键字（注意是关键字）可以得到结构体或类的对其字节
    cout<<"Person class' align size:"<<alignof(Person)<<endl;
    cout<<"sa's align size:"<<alignof(sa)<<endl;
    cout<<"sb's align size:"<<alignof(sb)<<endl;
    return 0;
}