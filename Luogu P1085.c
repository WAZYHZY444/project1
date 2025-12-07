#include <stdio.h>
int HOUR(int arr[]){
	int max=arr[0];
	int day=1;
	for(int i=0;i<7;i++){
		if(arr[i]>max){
			max=arr[i];
			day=i+1;
		}
	}
	if(max<=8){
		return 0;
	}else{
		return day;
	}
	
}
	
int main()
{
	int h1,h11,h2,h22,h3,h33,h4,h44,h5,h55,h6,h66,h7,h77;

	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d",&h1,&h11,&h2,&h22,&h3,&h33,&h4,&h44,&h5,&h55,&h6,&h66,&h7,&h77);
	int H1,H2,H3,H4,H5,H6,H7;
 	H1=h1+h11;
 	H2=h2+h22;
 	H3=h3+h33;
 	H4=h4+h44;
 	H5=h5+h55;
 	H6=h6+h66;
 	H7=h7+h77;
 	int hour[]={H1,H2,H3,H4,H5,H6,H7};
 	int result=HOUR(hour);
 	printf("%d",result);
	return 0;
}