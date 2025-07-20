class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int l=0,r=m-1;
        while(l<n&&r>=0){
            int cur=matrix[l][r];
            if(cur==target) return true;
            else if(target<cur) r--;
            else l++;
        }
        return false;
    }
};