class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> mpp;
        for(int v:arr1){
            while(!mpp.count(v)&&v>0){
                mpp.insert(v);
                v/=10;
            }
        }
        int res=0;
        for(int v:arr2){
           while(!mpp.count(v)&&v>0){
                v/=10;
            } 
            if(v>0) res=max(res,static_cast<int>(log10(v)+1));
        }
        return res;
    }
};