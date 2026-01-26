#include <stdio.h>

typedef struct member
{
	char name[20];
	int age;
	double score;
}mem;

int main()
{
	int n;
	scanf("%d",&n);
	mem p[n];
	for(int i=0;i<n;i++){
		scanf("%s %d %lf",p[i].name,&p[i].age,&p[i].score);
	}
	for(int i=0;i<n;i++){
		p[i].age=p[i].age+1;
		if(p[i].score!=0.0){
			double new_score=p[i].score*1.2;
			if(new_score<=600){
				p[i].score=new_score;
			}else{
				p[i].score=600;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%s %d %d\n",p[i].name,p[i].age,(int)p[i].score);
	}
	return 0;
}

//注意：语句(p[i].score*1.2)<=600是错误的，会导致p[i].score重复乘以1.2