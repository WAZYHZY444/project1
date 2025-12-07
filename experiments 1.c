#include <stdio.h>
#include <math.h>
int main()
{
	float x1,y1,x2,y2,x3,y3,midx1,midy1,midx2,midy2;
	scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
	
	float k1=(y1-y2)/(x1-x2);
	float k2=(y2-y3)/(x2-x3);
	
	float k11=-1/k1;
	float k22=-1/k2;
	
	midx1=(x1+x2)/2;
	midy1=(y1+y2)/2;
	midx2=(x2+x3)/2;
	midy2=(y2+y3)/2;
	
	float b1,b2;
	b1=midy1-k11*midx1;
	b2=midy2-k22*midx2;
	
	float Px,Py;
	Px=(b2-b1)/(k11-k22);
	Py=k11*Px+b1;
	
	float r;
	r=sqrt((Px-x1)*(Px-x1)+(Py-y1)*(Py-y1));
	
	printf("%f",r);
	return 0;
}