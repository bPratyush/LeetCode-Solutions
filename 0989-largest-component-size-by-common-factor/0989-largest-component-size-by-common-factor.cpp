class DSU{
public:
    vector<int>par;
    vector<int> rank;
    DSU(int n){
        par.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int findpar(int u){
        if(u==par[u]) return u;
        return par[u]=findpar(par[u]);
    }
    void unite(int u,int v){
        int ulp=findpar(u);
        int ulv=findpar(v);
        if(rank[ulp]<rank[ulv]) par[ulp]=ulv;
        else if(rank[ulv]<rank[ulp]) par[ulv]=ulp;
        else{
            par[ulp]=ulv;
            rank[ulv]++;
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        DSU dsu(maxNum + 1);
        // Union all numbers that share a common factor
        for (int num : nums) {
            for (int factor = 2; factor * factor <= num; factor++) {
                if (num % factor == 0) {
                    dsu.unite(num, factor);
                    dsu.unite(num, num / factor);
                }
            }
        }
        // Count the size of each component
        unordered_map<int, int> componentSize;
        int largestSize = 0;
        for (int num : nums) {
            int root = dsu.findpar(num);
            componentSize[root]++;
            largestSize = max(largestSize, componentSize[root]);
        }
        return largestSize;
    }
};