class Solution {
public:
    int minBitFlips(int start, int goal) {
      int res=start^goal, cnt=0;
      while(res){
        res&=(res-1);
        cnt++;
      }  
      return cnt;
    }
};