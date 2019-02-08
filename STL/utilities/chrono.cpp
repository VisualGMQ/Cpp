#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

template<typename T,typename R>
ostream& operator<<(ostream& os,const duration<T,R>& dur){
	cout<<"[base time:"<<R::num<<"/"<<R::den<<";"<<"tick:"<<dur.count()<<"]";
	return os;
}

int main(){
	cout.setf(ios_base::boolalpha);
	cout<<"to represent 'time' acurrly,we use 'duration' 'tick' 'epoch' 'timepoint' 4 concepts to represent 'time'"<<endl
		<<"durarion include a tick to represent number of basic time and a ratio to represent the basic time"<<endl;
	duration<int,ratio<60,1>> minute(1);
	cout<<"there are many predecalered duration:seconds,hours,milliseconds"<<endl;
	cout<<"the minute is:"<<minute<<endl;
	cout<<"the tick number of minute:"<<minute.count()<<endl;
	seconds min(60);	
	auto c = min + minute;
	cout<<"min:"<<min<<endl;
	cout<<"min+minute:"<<c<<endl;
	cout<<"min>minute:"<<(min>minute)<<endl;
}
