class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0;
        int even=0;
        for(auto it: position){
            if(it&1) odd++;
            else even++;

        }
        return min(odd,even);
    }
};