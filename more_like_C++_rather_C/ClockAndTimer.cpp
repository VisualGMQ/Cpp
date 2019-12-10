#include <iostream>
#include <chrono>
using namespace std;

/*
C++11提供了自己的时间库chrono,这个库以Duration，epoch和timepoint三个概念组成时间：
    * Duration：时间段，比如30分钟，用于表示多少个tick
    * epoch：时间片，代表一个时刻，比如2月1日
    * timepoint：时间点，比如1999年1月1日
*/

int main(int argc, char** argv){
    //duration模板的第一个参数是tick的类型，第二个可选参数表示tick的值。构造函数的参数是有多少个tick
    chrono::duration<int>   second(20);     //这里tick是一秒，一共20个tick（20s）
    chrono::duration<long, ratio<1, 1000> >  millisec(120); //这里tick是1/1000秒，一共120个tick（0.12s)
    chrono::milliseconds one_second(1000);  //chrono自带的duration，这里相当于duration<long, ratio<1, 1000>>
    chrono::hours day(24);  //一天
    chrono::system_clock clock;
    cout<<day.count()<<endl;
    return 0;
}