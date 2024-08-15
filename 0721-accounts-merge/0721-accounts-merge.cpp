class DSU{
    vector<int> par,rank;
public:
    DSU(int n){
        par.resize(n+1,0);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findpar(int u){
        if(u==par[u]) return u;
        return par[u]=findpar(par[u]);
    }
    void unite(int u,int v){
        int ulp=findpar(u);
        int ulv=findpar(v);
        if(ulp==ulv) return;
        if(rank[ulp]<rank[ulv]) par[ulp]=ulv;
        else if(rank[ulp]>rank[ulv]) par[ulv]=ulp;
        else{
            par[ulv]=ulp;
            rank[ulp]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()) mpp[mail]=i;
                else ds.unite(i,mpp[mail]);
            }
        }
        vector<string> merged[n];
        for(auto it:mpp){
            string mail=it.first;
            int u=ds.findpar(it.second);
            merged[u].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].empty()) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for(auto it:merged[i]) tmp.push_back(it);
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};