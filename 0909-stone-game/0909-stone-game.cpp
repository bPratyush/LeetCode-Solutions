class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int A=0,B=0;
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int flag=1;
        for(int i=n-1;i>=0;i--){
            if(flag) A+=piles[i];
            else B+=piles[i];
            flag=!flag;
        }
        return A>B;
    }
};