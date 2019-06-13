/*
OJ测试核心模块
作者：VisualGMQ
日期：2019.6.13

简介：这是模仿OJ系统的一个很小的功能模块,用于实现自动编译c++文件，并且传入输入和检测输出是否和预期相符。
使用方法：
    1.首先在控制台输入下列语句编译：
        g++ main.cpp -o oj -std=c++11
    2.在param.txt文件中给出你想要传给测试文件的参数（也就是测试文件中cin函数应该接受的字符串）
    3.在result.txt中给出你希望测试文件给出的结果
    4.然后通过下列语句运行测试:
        ./main xxx1.cpp xxx2.cpp

注意：目前只能在param.txt和result.txt中给出一个测试。多个测试无法实现。
 */
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
#define DEBUG

#ifdef DEBUG
#define log(msg) cout<<"At Time:"<<__TIME__<<"[Line"<<__LINE__<<"]->"<<endl<<#msg<<":"<<msg<<endl;
#else
#define log(msg) ;
#endif

using namespace std;

void readEntitleFile(string& text, istream& file){
    while(getline(file, text));
}

void OJ_Judg(string inputfile, string resultfile, string paramfile = "");

int main(int argc, char** argv){
    for(int i=1;i<argc;i++){
        OJ_Judg(argv[i], "./result.txt", "./param.txt");
    }
}

void OJ_Judg(string inputfile, string resultfile, string paramfile){
    ifstream isresult(resultfile.c_str());
    
    int index_dot = inputfile.find_last_of('.');
    log(inputfile);
    log(index_dot);
    string exename = "";
    for(int i=index_dot-1;inputfile[i] != '/' && i>=0;i--)
        exename.insert(exename.begin(), inputfile[i]);

    log(exename);
    log(resultfile);

    string compile_command = "g++ " + inputfile + " -o " + exename + " -std=c++11";
    log(compile_command);
    system(compile_command.c_str());

    long elapse = time(nullptr);
    string check_command;
    if(paramfile == "")
        check_command = "./" + exename + " > check.txt";
    else
        check_command = "./" + exename + " < " + paramfile + " > check.txt";
    elapse = time(nullptr) - elapse;

    log(check_command);
    system(check_command.c_str());

    ifstream checkfile("./check.txt");
    string checktext;
    readEntitleFile(checktext, checkfile);
    //checkfile>>checktext;

    if(isresult.fail()){
        cerr<<"result file not found"<<endl;
        return ;
    }
    string resulttext;
    readEntitleFile(resulttext, isresult);
    //isresult>>resulttext;

    log(checktext);
    log(resulttext);

    //TODO remove space breakline symbol at end of checktext and resulttext.
    if(checktext == resulttext){
        cout<<"pass test!"<<endl;
        cout<<"spent "<<elapse<<endl;
    }else{
        cout<<"not pass"<<endl;
    }

    string delete_command = "rm " + exename + " check.txt"; 
    system(delete_command.c_str());

    isresult.close();
}