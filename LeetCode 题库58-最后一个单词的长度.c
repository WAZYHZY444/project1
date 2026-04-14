int lengthOfLastWord(char* s) {
    int len=strlen(s);
    int i=len-1;
    int count=0;
    while(i>=0&&s[i]==' '){  //如果遇到了第一个非空格，就不会进入循环了
        i--;
    }
    while(i>=0&&s[i]!=' '){
        count++;
        i--;
    }
    return count;
}