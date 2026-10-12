#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	double A_pingjun=0.0;
	double A_fangcha=0.0;
	double A_guiyi=0.0;
	
	for(int i=0;i<n;i++){
		A_pingjun+=a[i];
	}
	A_pingjun/=n*1.0;
	
	for(int i=0;i<n;i++){
		A_fangcha+=((a[i]-A_pingjun)*(a[i]-A_pingjun));
	}
	A_fangcha/=n*1.0;
	
	for(int i=0;i<n;i++){
		A_guiyi=(a[i]-A_pingjun)/sqrt(A_fangcha);
		cout<<A_guiyi<<endl;
	}
	return 0;
}