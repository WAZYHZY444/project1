#include <stdio.h>
typedef struct date{
		int year;
		int month;
		int day;
}Date;

int Year(int year){  //判断是否为闰年
	return (year%400==0||year%4==0&&year%100!=0); //闰年返回1，平年返回0
}

int Month(int year,int month){
	int days[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//每一个月的天数
	if(month==2&&Year(year)){
		return 29;  //闰年的2月
	}
	return days[month];  //利用数组，通过数组的下标来找到对应月份的天数
}

long long Day(Date p){  //计算天数
	long long days=0;   //初始化
	for(int i=1;i<p.year;i++){  //计算年份贡献的天数
		if(Year(i)){
			days=days+366;
		}else{
			days=days+365;
		}
	}
	
	for(int j=1;j<p.month;j++){  //计算月份贡献的天数
		days=days+Month(p.year,j);
	}
	days=days+p.day;  //结构体给的当月的天数
	return days;
}
int main()
{
	Date startDate,endDate;
	scanf("%d %d %d",&startDate.year,&startDate.month,&startDate.day);
	scanf("%d %d %d",&endDate.year,&endDate.month,&endDate.day);
	long long days1=Day(startDate);
	long long days2=Day(endDate);
	printf("%lld\n",days2-days1);
	return 0;
}

