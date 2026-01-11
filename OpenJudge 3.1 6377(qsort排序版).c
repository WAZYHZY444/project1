#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Student
{
	int month;
	int date;
	char name[21];
}Student;

int cmp(const void* e1,const void* e2)
{
	int len1=strlen((char*)e1);
	int len2=strlen((char*)e2);
	if(len1==len2){
		return strcmp((char*)e1,(char*)e2);
	}
	if(len1!=len2){
		return (len1-len2);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	Student arr[180];
	for(int i=0;i<n;i++){
		scanf("%s %d %d",arr[i].name,&arr[i].month,&arr[i].date);
	}
	int mark=0;
	for(int i=1;i<13;i++){
		for(int j=1;j<32;j++){
			int count=0;
			char nameSame[180][21];
			for(int k=0;k<n;k++){
				if(arr[k].month==i&&arr[k].date==j){
					strcpy(nameSame[count],arr[k].name);   //注意nameSame用count作为索引
					count++;
				}
			}
			if(count>1){
				mark=1;
				qsort(nameSame,count,sizeof(nameSame[0]),cmp);
				printf("%d %d",i,j);
				for(int l=0;l<count;l++){
					printf(" %s",nameSame[l]);
				}
				printf("\n");
			}
		}
	}
	if(!mark){
		printf("None\n");
	}
	return 0;
}