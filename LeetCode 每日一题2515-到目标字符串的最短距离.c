int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int index[wordsSize];
    index[0]=-1;
    int k=0;
    for(int i=0;i<wordsSize;i++){
        if(strcmp(words[i],target)==0){
            index[k]=i;
            k++;
        }
    }
    if(index[0]==-1) return -1;
    int d1=0,d2=0,d=0;
    int cur=wordsSize;
    for(int j=0;j<k;j++){
        d1=abs((startIndex-index[j]));
        d2=wordsSize-d1;
        d=d1<d2?d1:d2;
        if(d<cur) cur=d;
    }
    return cur;
}

//优化版
int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
	int d1=0,d2=0,d=0;
    int cur=wordsSize;
    for(int i=0;i<wordsSize;i++){
        if(strcmp(words[i],target)==0){
            d1=abs((startIndex-i));
	        d2=wordsSize-d1;
	        d=d1<d2?d1:d2;
	        if(d<cur) cur=d;
        }
    }
    if(cur==wordsSize)return -1;
    else return cur;
}