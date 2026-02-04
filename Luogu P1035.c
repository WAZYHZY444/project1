#include <stdio.h>
#include <math.h>
int main()
{
	int k;
	int i=1;
	scanf("%d",&k);
	double Sn=0.0;
	while(Sn<=k){
		Sn+=1.0/i;
		i++;
	}
	printf("%d\n",i-1);  //多理解一下这里的i-1
	return 0;
}