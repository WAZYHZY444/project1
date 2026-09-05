#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N,NA,NB;
	cin>>N>>NA>>NB;
	vector<int> A,B;
	
	int a[NA];
	int b[NB];
	for(int i=0;i<NA;i++){
		cin>>a[i];
	}
	for(int i=0;i<NB;i++){
		cin>>b[i];
	}
	
	for(int i=0;i<N;i++){
		A.push_back(a[i%NA]);
	}
	
	for(int i=0;i<N;i++){
		B.push_back(b[i%NB]);
	}
	
	int countA=0;
	int countB=0;
	
	for(int i=0;i<N;i++){
		if(A[i]==0&&B[i]==2){
			countA++;
		}
		if(B[i]==0&&A[i]==2){
			countB++;
		}
		if(A[i]==2&&B[i]==5){
			countA++;
		}
		if(B[i]==2&&A[i]==5){
			countB++;
		}
		if(A[i]==5&&B[i]==0){
			countA++;
		}
		if(B[i]==5&&A[i]==0){
			countB++;
		}
	}
	
	if(countA>countB){
		cout<<"A";
	}
	else if(countA<countB){
		cout<<"B";
	}
	else{
		cout<<"draw";
	}
	
	return 0;
}