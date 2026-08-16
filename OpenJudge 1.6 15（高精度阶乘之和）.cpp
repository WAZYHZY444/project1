#include <iostream>
#include <vector>

using namespace std;

//高精度加法
void add(vector<int> &a,vector<int> &b)
{
	int key=0;  //存储下一位的进位
	int n=max(a.size(),b.size());
	for(int i=0;i<n||key;i++){  //carry成为最后a最高位进位的关键（a的长度加1）
		if(i==a.size()){
			a.push_back(0);  //i==a.size()-1时key非0，能继续进入循环，但仅进位需要增加一位
		}
		int sum=a[i]+(i<b.size()?b[i]:0)+key;
		a[i]=sum%10;
		key=sum/10;
	}
}

//高精度乘法
void multiply(vector<int> &a,int b)
{
	int key=0;
	for(int i=0;i<a.size()||key;i++){
		if(i==a.size()){
			a.push_back(0);
		}
		long long sum=(long long)a[i]*b+key;
		a[i]=sum%10;
		key=sum/10;
	}
	//去除前导零
	while(a.size()>1&&a.back()==0){  //a.back()获取vector最后一个元素
		a.pop_back();
	}
}


int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v.push_back(1);
	
	vector<int> sum;
	sum.push_back(0);
	
	for(int i=1;i<=n;i++){
		if(i>1){
			multiply(v,i);  //不需要重复计算阶乘，只需要乘以n得到的就是n的阶乘
		}
		//将当前阶乘累加到总和上
		add(sum,v);
	}
	
	for(int i=sum.size()-1;i>=0;i--){
		cout<<sum[i];
	}
	cout<<endl;
	return 0;
}