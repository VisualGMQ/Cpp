#include <iostream>
#include <random>   //随机数必须包括的头文件
using namespace std;

/*
随机数包含两部分：
    * 引擎：函数对象，用于作为随机性的源头，可以产生一个随机的无正负的随机值，一共有16个。以_engin结尾
    * 分布：函数对象，用于将引擎产生的随机值以某种方式转化为随机数。分为
        * 均匀分布
        * 伯努利分布
        * 柏松分布
        * 正态分布
        * 抽样分布
    以_distribution结尾

一般不会直接使用引擎，而是通过引擎和分布结合得到随机数。
*/

int main(int argc, char** argv){
    unsigned int seed = 10;                                 //你也可以使用chrono库来得到时间
    default_random_engine random_engin(seed);               //首先得到一个默认的随机数引擎
    uniform_int_distribution<unsigned int> dist(10, 20);    //均匀分布，模版参数必须是整型类型
    cout<<"int distribution in [10, 20]:";
    for(int i=0;i<10;i++)
        cout<<dist(random_engin)<<" ";
    cout<<endl;

    bernoulli_distribution ber_dist;                        //伯努利分布
    cout<<"bernoulli distribution :";
    for(int i=0;i<10;i++)
        cout<<ber_dist(random_engin)<<" ";
    cout<<endl;

    poisson_distribution<int> pois_dist;                    //柏松分布
    cout<<"poisson distribution :";
    for(int i=0;i<10;i++)
        cout<<pois_dist(random_engin)<<" ";
    cout<<endl; 

    normal_distribution<float> normal_dist;                 //正态分布
    cout<<"normal distribution :";
    for(int i=0;i<10;i++)
        cout<<normal_dist(random_engin)<<" ";
    cout<<endl;  
    return 0;
}