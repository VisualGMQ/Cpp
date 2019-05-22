#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
using namespace std;

int pipfile = open("myfifo", O_RDONLY|O_NONBLOCK);

void handlINT(int signum){
    if(signum == SIGINT){
        close(pipfile);  
        exit(EXIT_SUCCESS);
    }  
}

int main(int argc, char** argv){
    cout<<"read client opened"<<endl;
    signal(SIGINT, handlINT);
    if(pipfile <= 0){
        cout<<"no fifo to read"<<endl;
        return -1;
    }
    do{
        char buf[1024] = {'\0'};
        int len = read(pipfile, buf, sizeof(buf));
        if(len > 0){
            cout<<"len:"<<len<<" recived "<<buf<<endl;
        }
    }while(true);
    cout<<"read client closed"<<endl;
    return 0;
}