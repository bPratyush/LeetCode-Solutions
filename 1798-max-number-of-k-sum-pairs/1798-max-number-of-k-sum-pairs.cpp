class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        unordered_map<int,int>freq;
        int cnt=0;
        while(!pq.empty()){
            int tp=pq.top();
            pq.pop();
            int cmp=k-tp;
            if(freq[cmp]){
                freq[cmp]--;
                cnt++;
            }
            else freq[tp]++;
        }  
        return cnt;
    }
};