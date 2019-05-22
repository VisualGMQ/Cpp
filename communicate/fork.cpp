#include <iostream>
#include <cstring>
#include <unistd.h>
#include <wait.h>
using namespace std;
char data[] = "given data";

int main(int agrc, char** argv){
    //pip must created before fork a new progress!!!
    int pip[2];
    if(pipe(pip) == -1){
        cout<<"created pipe failed"<<endl;
        return -1;
    }
    int ref = fork();
    if(ref == 0){
        close(pip[1]);
        char buf[1024] = {'\0'};
        int len = read(pip[0], buf, sizeof(buf));
        cout<<"revieved "<<len<<endl;
        cout<<"read "<<buf<<endl;
        cout<<"this is child progress:"<<getpid()<<endl;
    }else if(ref > 0 ){
        close(pip[0]);
        write(pip[1], data, strlen(data));
        cout<<"this is parent progress:"<<getpid()<<endl;
        wait(nullptr);
    }else
        cout<<"generate progress error"<<endl;
    return 0;
}