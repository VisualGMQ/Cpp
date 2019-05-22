#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <string>
using namespace std;


int main(int argc, char** argv){
    cout<<"write client opened"<<endl;
    int ref = mkfifo("myfifo", 0777);
    if(ref == 0){
        cout<<"fifo created"<<endl;
    }
    int pipfile = open("myfifo", O_WRONLY|O_NONBLOCK);
    string str(argv[1]);
    str += " this is append msg";
    write(pipfile, str.c_str(), strlen(str.c_str()));
    float pi = 3.14159;
    close(ref);
    cout<<"write client closed"<<endl;
    return 0;
}