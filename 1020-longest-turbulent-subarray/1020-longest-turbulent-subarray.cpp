class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(),res=1,s=1,l=1;
        for(int i=0;i<n-1;i++){
            s=arr[i]<arr[i+1]?s+1:1;
            l=arr[i]>arr[i+1]?l+1:1;
            res=max(res,max(s,l));
            swap(s,l);
        }
        return res;
    }
};