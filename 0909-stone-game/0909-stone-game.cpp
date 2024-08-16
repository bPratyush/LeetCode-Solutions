class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int A=0,B=0;
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int alice=1;
        for(int i=n-1;i>=0;i--)
        {
            if(alice)   A+=piles[i];
            else    B+=piles[i];
            alice=!alice;
        }

        return A>B;
    }
};