#include <iostream>

using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int a[N][M+1];
	for(int i=0;i<N;i++){
		for(int j=0;j<M+1;j++){
			cin>>a[i][j];
		}
	}
	
	int sum=0;
	int min=1,minIndex=-1;
	for(int i=0;i<N;i++){
		int temp=0;
		for(int j=1;j<M+1;j++){
			sum+=a[i][j];
			temp+=a[i][j];
			if(temp<min){
				min=temp;
				minIndex=i;
			}
		}
	}
	for(int i=0;i<N;i++){
		sum+=a[i][0];
	}
	cout<<sum<<" "<<minIndex+1<<" "<<-min;
	return 0;
}
