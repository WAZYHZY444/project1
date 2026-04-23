int myAtoi(char* s) {
    int i=0;
    int tag=1;
    long long result=0;
    int len=strlen(s);
    while(i<len&&s[i]==' '){
        i++;
    }
    if(s[i]=='+'||s[i]=='-'){
        if(s[i]=='-'){
            tag=-1;
        }
        i++;
    }
    while(i<len){
        if(s[i]>'9'||s[i]<'0'){
           break;
        }
        result=result*10+(s[i]-'0');
        //需要提前截断，防止result溢出long long变成负数
        if (result>INT_MAX) break;
        i++;
    }
    result*=tag;
    if(result>INT_MAX) result=INT_MAX;
    if(result<INT_MIN) result=INT_MIN;
    return result;
}

int myAtoi(char* s){
	long long num = atoll(s);   //用库函数实现，需要头文件<stdlib.h>
    if(num>INT_MAX) num=INT_MAX;
    if(num<INT_MIN) num=INT_MIN;
    return num;
}