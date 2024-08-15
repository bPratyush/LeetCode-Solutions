class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> table;
        int ans=1;
        for(int i=0;i<arr.size();i++){
        table[arr[i]]=table[arr[i]-difference]+1;
        ans=max(ans,table[arr[i]]);
        }
        return ans;
    }
};