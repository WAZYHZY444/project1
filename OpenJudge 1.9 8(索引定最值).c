#include <stdio.h>
#include <math.h>
//关键：注意当出现多个最大值和多个最小值时，不要去除掉所有的最大值和最小值；当最大值和最小值相同时，只需要排除一个
//通过索引值来定位最大值和最小值
int main()
{
	int n;
	scanf("%d",&n);
	double arr[n];
	for(int i=0;i<n;i++){
		scanf("%lf",&arr[i]);
	}
	int max_i=0,min_i=0;
	for(int i=0;i<n;i++){
		if(arr[i]>arr[max_i]){
			max_i=i;  //更新最大值的位置
		}
		if(arr[i]<arr[min_i]){
			min_i=i;  //更新最小值的位置
		}
	}
	double sum=0;
	double ave=0;
	double ret;
	int count=0;
	for(int i=0;i<n;i++){
		if(i!=max_i&&i!=min_i){
			sum+=arr[i];
			count++;
		}else{
			if(max_i==min_i){
				if(i!=max_i){
					sum+=arr[i];
					count++;
				}
			}
		}
	}
	ave=sum/count;
	double MAX=0.0; //最大差值
	for(int i=0;i<n;i++){
		if(i!=max_i&&i!=min_i){
			ret=fabs(arr[i]-ave);
			if(ret>MAX){
				MAX=ret;
			}
		}else{
			if(max_i==min_i){
				if(i!=max_i){
					ret=fabs(arr[i]-ave);
					if(ret>MAX){
						MAX=ret;
					}
				}
			}
		}
	}
	printf("%.2f %.2f\n",ave,MAX);
	return 0;
}