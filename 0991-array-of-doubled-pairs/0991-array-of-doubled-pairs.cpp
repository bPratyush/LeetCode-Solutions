class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto it : arr) mp[it]++;
        sort(arr.begin(),arr.end());
        for(auto it : arr){
            if(!mp[it]) continue;
            mp[it]--;
            int val = 2*it;
            if(it<0 and it%2==0) val=it/2;
            if(!mp[val]) return false;
            mp[val]--;
        }
        return true;
    }
};