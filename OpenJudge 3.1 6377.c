#include <stdio.h>
#include <string.h>
int main()
{
	typedef struct Stu{
		char name[21];
		int month;
		int day;
	}Student;
	int n;
	scanf("%d",&n);
	Student stu[180];
//读入学生数据
	for(int i=0;i<n;i++){
		scanf("%s %d %d",stu[i].name,&stu[i].month,&stu[i].day);
	}
	int mark=0; //标记是否有生日相同的人
//遍历所有可能的日期(1月1日-12月31日)
	for(int month=1;month<=12;month++){
		for(int day=1;day<=31;day++){
			char nameStudent[180][21];  //创建临时数组：保存这一天出生的所有人的名字
			int count=0;  //记录这一天出生的人数
			for(int i=0;i<n;i++){
				if(stu[i].month==month&&stu[i].day==day){
					strcpy(nameStudent[count],stu[i].name); //把名字复制到临时数组
					count++;
				}
			}
			if(count>1){
				mark=1; //标记：找到了生日相同的人
				//用冒泡排序
				for(int i=0;i<count-1;i++){
					for(int j=0;j<count-1-i;j++){
						int len1=strlen(nameStudent[j]);
						int len2=strlen(nameStudent[j+1]);
						//两个名字长度不相同
						if(len1>len2){
							char temp[21];
							strcpy(temp,nameStudent[j]);
							strcpy(nameStudent[j],nameStudent[j+1]);
							strcpy(nameStudent[j+1],temp);
						}
						//长度相同，比较字典序
						else if(len1==len2){
							if(strcmp(nameStudent[j],nameStudent[j+1])>0){
								char temp[21];
								strcpy(temp,nameStudent[j]);
								strcpy(nameStudent[j],nameStudent[j+1]);
								strcpy(nameStudent[j+1],temp);
							}
						}
					}
				}
				printf("%d %d",month,day);
				for(int i=0;i<count;i++){
					printf(" %s",nameStudent[i]);
				}
				printf("\n");
			}
		}
	}
	//没有生日相同的人
	if(!mark){
		printf("None\n");
	}
	return 0;
}