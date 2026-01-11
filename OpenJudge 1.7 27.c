#include <stdio.h>
#include <string.h>
int main(){
    char line[501];  //根据题目要求，不超过500个字符
    
    //读取整行，保留所有空格
    fgets(line,sizeof(line),stdin);
    int len=strlen(line);
    
    //移除换行符
    line[strcspn(line,"\n")]='\0';
    
    int start=0;  //单词起始位置
    
    for(int i=0; i<=len;i++) {
        //遇到空格或字符串结束，说明一个单词结束
        if(line[i]==' '||line[i]=='\0'){
            //反转当前单词（从start到i-1）
            int left=start;
            int right=i-1;
            
            while(left<right){
                char temp=line[left];
                line[left]=line[right];
                line[right]=temp;
                left++;
                right--;
            }
            start=i+1;  //下一个单词的起始位置
        }
    }
    
    printf("%s\n",line);
    return 0;
}