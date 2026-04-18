int lengthOfLongestSubstring(char* s) {
    int len=strlen(s);
    if(len==0) return 0;
    int cur=0;
    int max=0;
    int mark=0;
    for(int i=0;i<len;i++){
        for(int j=i-1;j>=mark;j--){
            cur=i-mark;
            if(s[j]==s[i]){
                mark=j+1;
                cur=0;
                break;
            }
        }
        if(cur>max){
            max=cur;
        }
    }
    return max+1;
}