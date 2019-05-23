#include <iostream>
#include <cstdio>
#include <cstring>
#include "header.hpp"
using namespace std;

int main(int argc,char** argv){
    FILE* file = fopen("data.mem", "rb+");
    if(file == nullptr){
        cout<<"file not open"<<endl;
        return -2;
    }
    data d;
    fread(&d, sizeof(d), 1, file);
    cout<<"read suuccessful"<<endl 
            <<"data.m1:"<<endl 
            <<"a:"<<d.m1.a<<endl 
            <<"b:"<<d.m1.b<<endl 
        <<"data.m2"<<endl
        <<"a:"<<d.m2.a<<endl 
        <<"b:"<<d.m2.b<<endl
        <<"name:"<<d.name<<endl;
    fclose(file);
    member m;
    memcpy(&m, &d, sizeof(member));
    cout<<"strong cast successful"<<endl 
            <<"m.a:"<<m.a<<endl 
            <<"m.b:"<<m.b<<endl;
    return 0;
}
