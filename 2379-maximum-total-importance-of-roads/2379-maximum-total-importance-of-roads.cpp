class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>adj[n];
        for(auto road:roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        } 
        vector<long long>v;
        for(int i=0;i<n;i++) v.push_back(adj[i].size());
        long long sum=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++) sum += v[i]*(i+1);
        return sum;
    }
};