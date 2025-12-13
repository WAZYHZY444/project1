#include <stdio.h>
int main()
{
	typedef struct moneyStudent{
		char name[21];
		int result;      //期末评议成绩
		int classScore; //班级评议成绩
		char yn_1[2];  //是否是学生干部
		char yn_2[2];  //是否是西部省份
		int num;
	}MI;
	int n;
	scanf("%d",&n);
	MI stu[n];
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%s %d %d %s %s %d",stu[i].name,&stu[i].result,&stu[i].classScore,stu[i].yn_1,stu[i].yn_2,&stu[i].num);
	}
	for(int i=0;i<n;i++){
		int money=0;
		if(stu[i].result>80&&stu[i].num>=1){
			money+=8000;
		}
		if(stu[i].result>85&&stu[i].classScore>80){
			money+=4000;
		}
		if(stu[i].result>90){
			money+=2000;
		}
		if(stu[i].result>85&&stu[i].yn_2[0]=='Y'){
			money+=1000;
		}
		if(stu[i].classScore>80&&stu[i].yn_1[0]=='Y'){
			money+=850;
		}
		arr[i]=money;
	}
	int max=arr[0];
	int total=0;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		total+=arr[i];
	}
	for(int i=0;i<n;i++){
		if(arr[i]==max){
			printf("%s\n%d\n%d\n",stu[i].name,max,total);
			break;
		}
	}
	return 0;
}










