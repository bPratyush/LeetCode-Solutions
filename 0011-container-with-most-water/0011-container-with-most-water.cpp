class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,maxArea=0;
        while(l<r){
        int curr=min(height[l],height[r])*(r-l);
            maxArea = max(maxArea,curr);
            (height[l]<height[r])?l++:r--;
        }
        return maxArea;
    }
};