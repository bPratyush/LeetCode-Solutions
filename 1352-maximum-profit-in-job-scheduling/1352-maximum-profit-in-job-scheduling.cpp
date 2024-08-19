class Solution {
public:
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<int,pair<int,int>>>vp;
        for(int i=0;i<n;i++){
            vp.push_back(make_pair(startTime[i],make_pair(endTime[i],profit[i])));
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++){
            startTime[i]=vp[i].first;
            endTime[i]=vp[i].second.first;
            profit[i]=vp[i].second.second;
        }
        vector<int>dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            int nextJobIdx=lower_bound(startTime.begin()+idx,startTime.end(),endTime[idx])-startTime.begin();
            int  inc=profit[idx]+dp[nextJobIdx];
            int exc=dp[idx+1];
            dp[idx]=max(inc,exc);
        }
        return dp[0];
}
};