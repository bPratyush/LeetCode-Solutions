class Solution {
public:
    int cnt(int n,long pre1,long pre2){
        int steps=0;
        while(pre1<=n){
            steps+=min((long)(n+1),pre2)-pre1;
            pre1*=10;
            pre2*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur=1;
        k--;
        while(k>0){
            int step=cnt(n,cur,cur+1);
            if(step<=k) {
                cur++;
                k-=step;
            }
            else{
                cur*=10;
                k--;
            }
        }
        return cur;
    }
};