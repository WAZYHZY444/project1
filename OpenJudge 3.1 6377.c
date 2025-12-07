#include <stdio.h>
int main()
{
	typedef struct Stu{
		char name[21];
		int month;
		int day;
	}SI;
	int n;
	scanf("%d",&n);
	SI stu[n];
	for(int i=0;i<n;i++){
		scanf("%s %d %d",stu[i].name,&stu[i].month,&stu[i].day);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int mark=1;
			if(stu[i].month==stu[j].month&&stu[i].day==stu[j].day){
				int mark=0;
			}
		}
		if(!mark){
			
		}
	}
}