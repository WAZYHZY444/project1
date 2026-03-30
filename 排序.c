//直接插入排序
void InsertSort(int arr[],int n)
{
	for(int i=1;i<n;i++){
		if(arr[i]<arr[i-1]){
			int temp=arr[i];
			for(int j=i-1;j>=0;a[j]>temp&&j--){
				arr[j+1]=arr[j];
			}
			arr[j+1]=temp;
		}
	}
}

//直接插入排序（带哨兵）
void InsertSqort(int arr[],int n)
{
	for(int i=2;i<=n;i++){
		if(arr[i]<arr[i-1]){
			arr[0]=arr[i];
			for(int j=i-1;arr[0]<arr[j];j--){
				arr[j+1]=arr[j];
			}
		}
		arr[j+1]=arr[0];
	}
}

//折半插入查找   时间复杂度O(n^2)
void InsertSort(int arr[],int n)
{
	int left,right,mid;
	for(int i=2;i<=n;i++){
		arr[0]=arr[i];
		left=1,right=i-1;
		while(left<=right){
			mid=(left+right)/2;
			if(arr[mid]>arr[0]){
				right=mid-1;
			}else{
				left=mid+1;
			}
		}
		for(j=i-1;j>=left;j--){
			arr[j+1]=arr[j];
		}
		arr[left]=arr[0];
	}
}

//希尔排序
void ShellSort(int arr[],int n)
{
	for(int d=n/2;d>=1;d=d/2){
		for(int i=d+1;i<=n;i++){
			if(arr[i]<arr[i-d]){
				arr[0]=arr[i];
				for(j=i-d;j>0&&arr[0]<arr[j];j-=d){
					arr[j+d]=arr[j];
				}
				arr[j+d]=arr[0];
			}
		}
	}
}

//冒泡排序(往后冒)
void BubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++){
		int flag=1;
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=0;
			}
		}
		if(flag==1){
			return 0;
		}
	}
}

//冒泡排序(往后冒)
void BubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++){
		int flag=1;
		for(int j=n-1;j>i;j--){
			if(arr[j-1]>arr[j]){
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
				flag=0;
			}
		}
		if(flag==1){
			return;
		}
	}
}