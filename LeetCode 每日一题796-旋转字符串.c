//方法一
bool rotateString(char* s, char* goal) {
    int len1=strlen(s);
    int len2=strlen(goal);
    if(len1!=len2) return false;
    if(len1==0) return true;
    for(int i=0;i<len1;i++){
        int tag=1;
        for(int j=0;j<len1;j++){
            if(s[(i+j)%len1]!=goal[j]){
                tag=0;
                break;
            }
        }
        if(tag==1) return true;
    }
    return false;
}

//方法二
bool rotateString(char* s, char* goal) {
	int len1=strlen(s);
    int len2=strlen(goal);
    if(len1!=len2) return false;
    if(len1==0) return true;
    char str[200];
    //旋转字符串：s+s一定包含goal
    strcpy(str,s);
    strcat(str,goal);
    //判断是否包含字串
    if(strstr(str,goal)){
    	return true;
	}
	return false;
}