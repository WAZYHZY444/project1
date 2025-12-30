#include <stdio.h>
#include <stdlib.h>
typedef struct Stu
{
	int Score_Chi;
	int Score_Mat;
	int Score_Ein;
}Stu;

typedef struct Arr
{
	int num;
	int Score_sum;
}Arr;

int cmp_int(const void* e1,const void* e2){
	return ((Arr*)e2)->Score_sum-((Arr*)e1)->Score_sum;     //降序
}

int main()
{
	int n;
	scanf("%d",&n);
	Stu s[n];
	Arr arr[n];
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&s[i].Score_Chi,&s[i].Score_Mat,&s[i].Score_Ein);
	}
	for(int i=0;i<n;i++){
		arr[i].num=i+1;
		arr[i].Score_sum=s[i].Score_Chi+s[i].Score_Mat+s[i].Score_Ein;
	}
	int sz=sizeof(arr)/sizeof(arr[0]);
	qsort(arr,sz,sizeof(arr[0]),cmp_int);
	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if(arr[j].Score_sum==arr[j+1].Score_sum){
				if(s[arr[j].num-1].Score_Chi<s[arr[j+1].num-1].Score_Chi){
					Arr temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
				else if(s[arr[j].num-1].Score_Chi==s[arr[j+1].num-1].Score_Chi){
					if(arr[j+1].num<arr[j].num){
						Arr ret=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=ret;
					}
				}
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%d %d\n",arr[i].num,arr[i].Score_sum);
	}
	return 0;
}