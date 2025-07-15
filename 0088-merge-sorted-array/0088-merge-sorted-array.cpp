class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
       int i=0,j=0,k=0;
       vector<int> res(n+m);
       while(i<m&&j<n){
        if(a[i]<=b[j]) res[k++]=a[i++];
        else res[k++]=b[j++];
       } 
       while(i<m) res[k++]=a[i++];
       while(j<n) res[k++]=b[j++];
       for(int i=0;i<m+n;i++) a[i]=res[i]; 
    }
};