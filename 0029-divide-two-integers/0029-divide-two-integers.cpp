class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        unsigned int res=0;
        int sgn=1;
        if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) sgn=-1;
        unsigned int dvd = abs((long long)dividend);
        unsigned int div = abs((long long)divisor);
        while(dvd>=div){
            int cnt=0;
            while(dvd>(div<<(cnt+1))) cnt++;
            dvd-=div<<cnt;
            res+=1<<cnt;
        }
        if(res==(1<<31)&&sgn==1) return INT_MAX;
        return sgn*res;
    }
};