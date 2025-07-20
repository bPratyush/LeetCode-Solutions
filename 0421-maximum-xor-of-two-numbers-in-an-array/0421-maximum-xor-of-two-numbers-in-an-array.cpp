class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask=0,res=0;
        for(int i=31;i>=0;i--){
            mask|=(1<<i);
            unordered_set<int>st;
            for(int num:nums) st.insert(mask&num);
            int tmp=res|(1<<i);
            for(int s:st){
                if(st.find(tmp^s)!=st.end()){
                    res=tmp;
                    break;
                }
            }
        }        
        return res;
    }
};