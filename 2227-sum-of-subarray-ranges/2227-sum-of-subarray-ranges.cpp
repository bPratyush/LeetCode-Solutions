class Solution {
public:
    vector<int> NGE(vector<int>&nums){
        stack<int> st;
        int n=nums.size();
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) nge[i]=st.top();
            else nge[i]=n;
            st.push(i);
        }
        return nge;
    }
    vector<int> NSE(vector<int>&nums){
        stack<int> st;
        int n=nums.size();
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>nums[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            else nse[i]=n;
            st.push(i);
        }
        return nse;
    }
    vector<int> PGE(vector<int>&nums){
        stack<int> st;
        int n=nums.size();
        vector<int> pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) pge[i]=st.top();
            else pge[i]=-1;
            st.push(i);
        }
        return pge;
    }
    vector<int> PSE(vector<int>&nums){
        stack<int> st;
        int n=nums.size();
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            else pse[i]=-1;
            st.push(i);
        }
        return pse;
    }
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        vector<int> pge=PGE(nums);
        vector<int> pse=PSE(nums);
        vector<int> nse=NSE(nums);
        vector<int> nge=NGE(nums);
        long long largest=0,smallest=0;
        for(int i=0;i<nums.size();i++){
            int left=(i-pge[i]),right=(nge[i]-i);
            largest+=left*1LL*right*nums[i];
            int lefti=(i-pse[i]),righti=(nse[i]-i);
            smallest+=lefti*1LL*righti*nums[i];
        }
        return largest-smallest;
    }
};