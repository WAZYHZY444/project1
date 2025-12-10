#include <stdio.h>
int main()
{
	int count[2000000];
	int n,m,sub;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&sub);
		count[sub]++;
	}
	for(int i=1;i<=n;i++){
		while(count[i]>0){
			printf("%d ",i);
			count[i]--;
		}
	}
	return 0;
}