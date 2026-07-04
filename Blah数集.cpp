/*
[队列：Blah数集]
大数学家高斯小时候偶然间发现一种有趣的自然数集合Blah，对于以a为基的集合Ba定义如下：
(1)a是集合Ba的基，且a是Ba的第一个元素；
(2)如果x在集合Ba中，则2x+1和3x+1也都在集合Ba中；
(3)没有其他元素在集合Ba中了。
现在小高斯想知道如果将集合Ba中元素按照升序排列，第N个元素会是多少？
输入:
输入包括很多行，每行输入包括两个数字，集合的基a(1<=a<=50)以及所求元素序号n(1<=n<=1000000)
输出:
对丁每个输入，输出集合Ba的第n个元素值
样例输入:
1 100
28 5437
样例输出:
418
900585
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXN=10000;

int main()
{
	int a,n;
	vector<int> result;
	
	while(cin>>a>>n){
		int arr[MAXN];
		arr[1]=a;  //第一个元素是a
		
		//p2指向当前用于生成2x+1的位置，p3指向当前用于生成3x+1的位置
		int p2=1,p3=1;
		
		for(int i=2;i<=n;i++){ //已经生成了1个元素
			//计算两个候选值
			int val2=arr[p2]*2+1;
			int val3=arr[p3]*3+1;
			
			//取最小的那个
			if(val2<val3){
				arr[i]=val2;
				p2++;
			}else if(val2>val3){
				arr[i]=val3;
				p3++;
			}else{
				arr[i]=val2;
				p2++;
				p3++;
			}
		}
		result.push_back(arr[n]);
	}
	for(int ret:result){
		cout<<ret<<endl;
	}
	return 0;
}