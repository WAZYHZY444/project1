#include <stdio.h>
typedef struct Date
{
	int Year;
	int Month;
	int Day;
}Date;

int isLeapYear(int year)
{
	return (year%4==0&&year%100!=0||year%400==0);
}

int Days_Month(int month,int year)
{
	int arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(month==2&&isLeapYear(year)){
		return 29;
	}
	return arr[month];
}

int Days(Date d1,Date d2)
{
	//d1和d2同年
	if(d1.Year==d2.Year){
		int days1=0;
		for(int i=1;i<d1.Month;i++){
			days1+=(Days_Month(i,d1.Year));
		}
		days1+=d1.Day;
	
		int days2=0;
		for(int i=1;i<d2.Month;i++){
			days2+=(Days_Month(i,d2.Year));
		}
		days2+=d2.Day;
	
		return days2-days1;	
	}
	
	//d1和d2不同年
	int day_year=0;
	for(int i=d1.Year+1;i<d2.Year;i++){
		if(isLeapYear(i)){
			day_year+=366;
		}else{
			day_year+=365;
		}	
	}
	if(d1.Year!=d2.Year){
		//d1剩余的天数
		int days_1=0;
		for(int i=d1.Month+1;i<13;i++){
			days_1+=(Days_Month(i,d1.Year));
		}
		days_1+=(Days_Month(d1.Month,d1.Year)-d1.Day);
		
		//d2已过的天数
		int days_2=0;
		for(int i=1;i<d2.Month;i++){
			days_2+=(Days_Month(i,d2.Year));
		}
		days_2+=d2.Day;
		return day_year+days_1+days_2;
	}
}

int main()
{
	Date Start,End;
	scanf("%d %d %d",&Start.Year,&Start.Month,&Start.Day);
	scanf("%d %d %d",&End.Year,&End.Month,&End.Day);
	int days=Days(Start,End);
	printf("%d\n",days);
	return 0;
}

// 使用数学公式直接计算天数
/*
long long days_from_start(Date d){
    int y=d.year;
    int m=d.month;
    int day=d.day;
    
    // 调整月份
    if(m<2){
        y--;
        m+=12;
    }
    
    // 公式计算
    return 365LL*y+y/4-y/100+y/400+(153*m-457)/5+day-306;    //365LL long long类型
}
*/