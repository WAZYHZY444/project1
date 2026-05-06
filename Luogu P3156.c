#include <stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	long long nn[n];
	int mm[m];
	for(int i=0;i<n;i++){
		scanf("%lld",&nn[i]);
	}
	for(int j=0;j<m;j++){
		scanf("%d",&mm[j]);
	}
	for(int i=0;i<m;i++){
		printf("%lld\n",nn[mm[i]-1]);
	}
	return 0;
}