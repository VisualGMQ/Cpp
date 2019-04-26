#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include "header.hpp"
using namespace std;

int main(int argc,char** argv){
    FILE* file = fopen("data.mem", "wb+");
    if(file == nullptr){
        cout<<"file can't open"<<endl;
        return -1;
    }
    data d;
    d.m1.a=10;
    d.m1.b=20;
    d.m2.a=30;
    d.m2.b=40;
    d.name="VisualGMQ";
    fwrite(&d, sizeof(d), 1, file);
    rewind(file);
    fclose(file);
    return 0;
}


