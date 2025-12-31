#include <stdio.h>
//判断是否为闰年
int isLeapYear(int year){
	if(year%4==0&&year%100!=0||year%400==0){
		return 366;
	}else{
		return 365;
	}
}

//计算某年某月的天数
int DayMonth(int year,int month){
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(month==2&&isLeapYear(year)){
		return 29;
	}
	return days[month-1];
}

//计算从1900年1月1日到目标月1日的总天数
int DayYear(int year,int month){
	int total_days=0;
	 // 计算1900年到year-1年的总天数
	for(int i=1900;i<year;i++){
		total_days+=isLeapYear(i);	
	}
	// 计算year年1月到month-1月的总天数
	for(int j=1;j<month;j++){
		total_days+=DayMonth(year,j);
	}
	return total_days;
}

int main()
{
	int year,month;
	scanf("%d %d",&year,&month);
	
	int total_days=DayYear(year,month);
	int firstDay=(total_days+1)%7;    //计算该月1日是星期几
	
	int days_month=DayMonth(year,month);
	
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	
	for(int i=0;i<firstDay;i++){
		printf("    ");     //四个空格，对应表头的三个字母加一个空格
	}
	
	int currentDay=firstDay;
	for(int j=1;j<=days_month;j++){
		//打印日期
		printf("%3d",j);
		if(currentDay==6){
			printf("\n");  //换行
		}else{
			printf(" ");  //日期之间的空格
		}
		//更新星期，目的是实时更新，对是否换行做出准确判断
		currentDay=(currentDay+1)%7;
	}
	return 0;	
}