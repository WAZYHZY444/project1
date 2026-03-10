int romanToInt(char* s){
    int len=strlen(s);
    int sum=0;
    for(int i=0;i<len;i++){
        int result1=0;
        switch(s[i]){
            case 'I':result1=1;break;
            case 'V':result1=5;break;
            case 'X':result1=10;break;
            case 'L':result1=50;break;
            case 'C':result1=100;break;
            case 'D':result1=500;break;
            case 'M':result1=1000;break;
        }
        int result2=0;
        if(i+1<len){
            switch(s[i+1]){
                case 'I':result2=1;break;
                case 'V':result2=5;break;
                case 'X':result2=10;break;
                case 'L':result2=50;break;
                case 'C':result2=100;break;
                case 'D':result2=500;break;
                case 'M':result2=1000;break;
            }
        }
        if(result1<result2){
            sum+=result2-result1;
            i++;
        }else{
            sum+=result1;
        }
    }
    return sum;
}