class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mpp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums2[st.top()]<=nums2[i]) st.pop();
            if(!st.empty()) mpp[nums2[i]]=nums2[st.top()];
            else mpp[nums2[i]]=-1;
            st.push(i);
        }
        for(auto &x:nums1) x=mpp[x];
        return nums1;
    }
};