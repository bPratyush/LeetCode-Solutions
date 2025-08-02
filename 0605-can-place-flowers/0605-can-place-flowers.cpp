class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0, N=flowerbed.size();
        for(int i=0;i<N;i++){
            if(!flowerbed[i]){
                bool lempty=(i==0 || flowerbed[i-1]==0);
                bool rempty=(i==N-1 || flowerbed[i+1]==0);
            if(lempty&&rempty){
                flowerbed[i]=1;
                cnt++;
            }
        }
        }
        return cnt>=n;
    }
};