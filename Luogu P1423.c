#include <stdio.h>
int main()
{
	double s;
	double len=2.0;
	double Len=0;
	int n=0;
	scanf("%lf",&s);
	while(Len<s){
		n++;
		Len+=len;
		len*=0.98;
	}
	printf("%d\n",n);
	return 0;
}