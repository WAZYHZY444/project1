#include <stdio.h>
int main()
{
	typedef struct stu
	{
		int score;
		char name[21];	
	}SI;
	int n;
	scanf("%d",&n);
	SI stu[n];
	for(int i=0;i<n;i++){
		scanf("%d %s",&stu[i].score,stu[i].name);
	}
	int max=stu[0].score;
	int i_max=0;
	for(int i=0;i<n;i++){
		if(stu[i].score>max){
			max=stu[i].score;
			i_max=i;  //记录索引的最大值
		}
	}
	printf("%s\n",stu[i_max].name);
	return 0;
}