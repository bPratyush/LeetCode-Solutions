class Solution {
public:
    vector<int> merge(vector<int>&a,vector<int>&b){
        int n=a.size(),m=b.size();
        int i=0,j=0,k=0;
        vector<int>res(n+m);
        while(i<n&&j<m){
            if(a[i]<=b[j]) res[k++]=a[i++];
            else res[k++]=b[j++];
        }
        while(i<n) res[k++]=a[i++];
        while(j<m) res[k++]=b[j++];
        return res;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res=merge(nums1,nums2);
        int n=res.size();
        if(n%2!=0) return res[n/2];
        return (double) (res[n/2]+res[n/2-1])/2;
    }
};