#include <iostream>

using namespace std;

const int MAXN=20;

int n,sum=0;
int x[MAXN];

void backTrack(int t)
{
	if(t>n){
		for(int i=1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
		sum++;
		return;
	}else{
		for(int i=t;i<=n;i++){
			//去除重复排列（有相同的元素）
			int ok=1;
			for(int j=t;j<i;j++){
				if(x[i]==x[j]){
					ok=0;
					break;
				}
			}
			if(ok){
				swap(x[i],x[t]);
				backTrack(t+1);
				swap(x[i],x[t]);
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	backTrack(1);
	return 0;
}