class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lh=INT_MIN,rh=INT_MIN,ans=0;
        while(l<r){
            lh=max(lh,h[l]);
            rh=max(rh,h[r]);
            ans+=(lh<rh)?(lh-h[l++]):(rh-h[r--]);
        }
        return ans;
    }
};