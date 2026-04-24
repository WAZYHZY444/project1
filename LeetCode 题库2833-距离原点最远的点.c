int furthestDistanceFromOrigin(char* moves) {
    int len=strlen(moves);
    int count1=0,count2=0;
    for(int i=0;i<len;i++){
        if(moves[i]=='L')
            count1++;
        if(moves[i]=='R')
            count2++;
    }
    int tag=(count1>count2)?1:0;
    int index=0;
    for(int i=0;i<len;i++){
        if(moves[i]=='L'){
            index--;
        }
        else if(moves[i]=='R'){
            index++;
        }
        else if(tag==1&&moves[i]=='_'){
            index--;
        }
        else if(tag==0&&moves[i]=='_'){
            index++;
        }
    }
    return abs(index);
}