#include <iostream>
#include <future>
#include <thread>
using namespace std;

int main(){
	cout<<this_thread::get_id()<<" main thread is run"<<endl;
	packaged_task<int(void)> task([](){
				cout<<this_thread::get_id()<<endl;
				return 10;
			});
	future<int> result = task.get_future();
	thread th(std::move(task));
	th.join();
	cout<<"the result is:"<<result.get()<<endl;
	return 0;
}
