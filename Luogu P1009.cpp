#include <iostream>

using namespace std;

const int MAX=200;

void Multiply(int a[],int &len,int b)
{
	int temp=0;
	for(int i=0;i<len;i++){
		int mul=a[i]*b+temp;
		a[i]=mul%10;
		temp=mul/10;
	}
	while(temp){
		a[len++]=temp%10;  //注意：后缀++是先使用后改变
		temp/=10;
	}
}

void Add(int a[],int &lena,const int b[],int lenb)
{
	int temp=0;
	int maxlen=max(lena,lenb);
	for(int i=0;i<maxlen;i++){
		int sum=temp;
		if(i<lena) sum+=a[i];
		if(i<lenb) sum+=b[i];
		a[i]=sum%10;
		temp=sum/10;
	}
	if(temp){
		a[maxlen++]=temp;
	}
	lena=maxlen;
}

void Print(const int a[],int len)
{
	for(int i=len-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	
	int total[MAX]{0};
	int totallen=1;
	
	for(int i=1;i<=n;i++){
		int A[MAX]={0};
		A[0]=1;
		int len=1;
		
		for(int j=2;j<=i;j++){
			Multiply(A,len,j);
		}
		Add(total,totallen,A,len);
	}
	Print(total,totallen);
	
	return 0;
}

