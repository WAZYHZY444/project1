//求子列的最大值

//算法一：
int MaxSubseqSum1(int A[],int N)
{
	int ThisSum,MaxSum=0;
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			ThisSum=0;
			for(int k=i;k<=j;k++){
				ThisSum+=A[k];
				if(ThisSum>MaxSum){
					MaxSum=ThisSum;
				}
			}
		}
	}
	return MaxSum;
}