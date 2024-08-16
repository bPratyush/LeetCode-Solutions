class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n=heights.size(),m=heights[0].size();
       vector<vector<int>> eff(n,vector<int>(m,INT_MAX));
       vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       pq.push({0,{0,0}});
        eff[0][0]=0;
        vector<pair<int,int>> del={{-1,0},{0,1},{0,-1},{1,0}};
        while(!pq.empty()){
            int efi=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1) return efi;
            for(int i=0;i<4;i++){
                int nrow=r+del[i].first;
                int ncol=c+del[i].second;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    int newefi=max(efi,abs(heights[nrow][ncol]-heights[r][c]));
                    if(newefi<eff[nrow][ncol]){
                        eff[nrow][ncol]=newefi;
                        pq.push({newefi,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};