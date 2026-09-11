#include <iostream>

using namespace std;

//递归法（时间复杂度O(logn))
double exp1(double a,int n)
{
	if(a==0) return 0;
	if(n==0) return 1;
	else{
		int x=exp1(a,n/2);  //(a^(n/2))^2
		if(n%2!=0){    //n是奇数
			return a*x*x;
		}else{
			return x*x;
		}
	}
}

//非递归法（时间复杂度O(logn))
double exp2(double a,int n)
{
	double temp=a,res=1.0;
	int i=n;
	while(i>0){
		if(i%2!=0){  //i是奇数
			res*=temp;            //a^93 = a^64 * a^16 * a^8 * a^4 * a
		}
		
		i/=2;
		temp*=temp;
	}
	return res;
}

int main()
{
	double a;
	int n;
	cin>>a>>n;
	
	//处理负指数
	if(n<0){
		a=1/a;
		n=-n;
	}
	double res1=exp2(a,n);
	double res2=exp1(a,n);
	cout<<res1<<endl;
	cout<<res2<<endl;
	return 0;
}