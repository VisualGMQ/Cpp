#include <iostream>
#include <mysql.h>
using namespace std;

int main(){
    cout<<"Hello Mysql"<<endl;
    MYSQL connect;
    mysql_init(&connect);

    mysql_close(&connect);
    return 0;
}