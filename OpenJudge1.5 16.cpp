#include <iostream>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	double price=200.0;  //房价
	double savings=0.0;  //存款
	double rate=1.0+K/100.0;
	
	for(int year=1;year<=20;year++){
		savings+=N;
		if(savings>=price){
			cout<<year<<endl;
			return 0;
		}
		price*=rate;
	}
	cout<<"Impossible"<<endl;
	return 0;
}