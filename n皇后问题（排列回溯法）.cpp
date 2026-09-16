#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=20;
int x[MAXN];  //x[1……n]解向量，第k行皇后放在x[k]列
int sum;      //记录方案总数
int n;

bool place(int k)
{
	for(int j=1;j<k;j++){
		if(abs(k-j)==abs(x[j]-x[k])){   //对角线冲突 abs(k-j)行差，abs(x[j]-x[k])列差
			return false;
		}
	}
	return true;
}

void backTrack(int t)
{
	if(t>n){
		sum++;
		cout<<"方案"<<sum<<"：";
		for(int i=1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}else{
		for(int i=t;i<=n;i++){
			//不同列：不能有两行皇后的列号相同，x[1]、x[2]……x[n]不重复（全排列）
			//交换实现全排列，自动满足不同行不同列
			swap(x[t],x[i]);
			if(place(t)){
				backTrack(t+1);  //递归放下一行
			}
			swap(x[t],x[i]);  //回溯复原
		}
	}
	
}

int main()
{
	cout<<"输入皇后个数：";
	cin>>n;
	sum=0;
	//初始化
	for(int i=1;i<=n;i++){
		x[i]=i;
	}
	backTrack(1);
	cout<<"总方案数："<<sum<<endl;
	return 0;
}