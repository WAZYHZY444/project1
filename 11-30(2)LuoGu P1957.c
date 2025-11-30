//#include <stdio.h>
//#include <string.h>
//int Add(int x,int y)
//{
//	return x+y;
//}
//int Sub(int x,int y)
//{
//	return x-y;
//}
//int Mul(int x,int y)
//{
//	return x*y;
//}
//
//int(*arr[4])(int,int)={0,Add,Sub,Mul};
//char option[4]={' ','+','-','*'};
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	getchar();
//	char ch[100][100];  //存储n行输入
//	int marks[100];  //存储每行的标记
//	int p_mark=0; //上一行的标记
//	for(int i=0;i<n;i++){
//		scanf(" %[^\n]",ch);
//		int mark=p_mark; //默认使用上一行标记
//		
//		int x=0,y=0;
//		if(ch[0]>='a'&&ch[0]<='c'){
////①字母 数字 数字
//			mark=ch[0]-'a'+1;
//			int j=2;  //找到第一个空格后的数字
//			while(ch[j]==' '){
//				j++;  //跳过字母和第一个空格
//			}
//			//转化第第一个数字
//			while(ch[j]>='0'&&ch[j]<='9'){
//				x=x*10+(ch[j]-'0');  //把字符数字转换成整型数字
//				j++;
//			}
//			//跳过空格
//			while(ch[j]==' '){
//				j++;  //跳过字母和第一个空格
//			}
//			//转换第二个数字
//			while(ch[j]>='0'&&ch[j]<='9'){
//			    y=y*10+(ch[j]-'0');  //把字符数字转换成整型数字
//				j++;
//			}
//		}else{
////②数字 数字
//			int j=0;
//			//转换第一个数字
//			while(ch[j]>='0'&&ch[j]<='9'){
//				x=x*10+(ch[j]-'0');  //把字符数字转换成整型数字
//				j++;
//			}
//			//跳过空格
//			while(ch[j]==' '){
//				j++;  //跳过字母和第一个空格
//			}
//			//转换第二个数字
//			while(ch[j]>='0'&&ch[j]<='9'){
//			    y=y*10+(ch[j]-'0');  //把字符数字转换成整型数字
//				j++;
//			}
//		}
//		// 计算结果
//        int ret = arr[mark](x, y);
//        
//        // 构建计算表达式字符串
//        
//        char expression[100];
//        sprintf(expression, "%d%c%d=%d", x, option[mark], y, ret);
//        int len = strlen(expression);
//        
//        // 输出计算结果和表达式长度
//        printf("%s\n", expression);
//        printf("%d\n", len);
//        
//        p_mark = mark;  // 更新上一行标记
//    }
//    
//    return 0;
//}
//
//
//
#include <stdio.h>
#include <string.h>

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }
int Mul(int x, int y) { return x * y; }

int (*arr[4])(int, int) = {0, Add, Sub, Mul};
char option[4] = {' ', '+', '-', '*'};

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    
    // 只存储关键信息：x, y, 标记
    int x_values[100], y_values[100], marks[100];
    int p_mark = 0;
    
    // 第一阶段：读取并解析所有输入
    for(int i = 0; i < n; i++) {
        char ch[100];
        scanf(" %[^\n]", ch);
        
        int mark = p_mark;
        int x = 0, y = 0;
        
        if(ch[0] >= 'a' && ch[0] <= 'c') {
            mark = ch[0] - 'a' + 1;
            int j = 2;
            while(ch[j] == ' ') j++;
            while(ch[j] >= '0' && ch[j] <= '9') {
                x = x * 10 + (ch[j] - '0');
                j++;
            }
            while(ch[j] == ' ') j++;
            while(ch[j] >= '0' && ch[j] <= '9') {
                y = y * 10 + (ch[j] - '0');
                j++;
            }
        } else {
            int j = 0;
            while(ch[j] >= '0' && ch[j] <= '9') {
                x = x * 10 + (ch[j] - '0');
                j++;
            }
            while(ch[j] == ' ') j++;
            while(ch[j] >= '0' && ch[j] <= '9') {
                y = y * 10 + (ch[j] - '0');
                j++;
            }
        }
        
        // 存储关键信息
        x_values[i] = x;
        y_values[i] = y;
        marks[i] = mark;
        p_mark = mark;
    }
    
    // 第二阶段：统一输出
    for(int i = 0; i < n; i++) {
        int ret = arr[marks[i]](x_values[i], y_values[i]);
        char expr[100];
        sprintf(expr, "%d%c%d=%d", x_values[i], option[marks[i]], y_values[i], ret);
        
        printf("%s\n", expr);
        printf("%d\n", strlen(expr));
    }
    
    return 0;
}