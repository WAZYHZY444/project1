//C语言（重视int类型取值范围问题）
int divide(int dividend, int divisor) {
    if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
    long result=0;
    long a=llabs((long)dividend);
    long b=llabs((long)divisor);
    while(a>=b){
        long temp=b;
        long count=1;
        //除数翻倍，判断话能不能继续翻倍（算法题里默认用移位表示翻倍）
        while(a>=(temp<<1)){  //temp<<1 -> temp*2
            temp<<=1;         //temp<<=1 -> temp=temp*2
            count<<=1;
        }
        a-=temp;
        result+=count;
    }
    if((dividend>=0&&divisor>0)||(dividend<0&&divisor<0))
        return result;
    else
        return -result;
}

//python（注意这是在C语言环境，不能运行）
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend==-2**31 and divisor==-1:
            return 2**31-1
        result=0
        a=abs(dividend)
        b=abs(divisor)
        while a>=b:
            temp=b
            count=1
            while a>=(temp*2):
                temp*=2
                count*=2
            a-=temp
            result+=count
        if (dividend<0 and divisor>0) or (dividend>0 and divisor<0):
            result=-result
        if result<-2**31:
            result=-2**31
        if result>2**31-1:
            result=2**31-1
        return result