class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rsize=matrix.size();
        int csize=matrix[0].size();
        int l=0,r=rsize*csize-1;
        int mid=l+(r-l)/2;
        while(l<=r){
            int elem=matrix[mid/csize][mid%csize];
            if(target==elem) return 1;
            else if(target<=elem) r=mid-1;
            else l=mid+1;
            mid=l+(r-l)/2;
        }
        return 0;
    }
};