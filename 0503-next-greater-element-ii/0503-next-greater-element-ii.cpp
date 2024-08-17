class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        unordered_map<int,int>m;
        stack<int>st;
        int n=v.size();
        vector<int> ans(n,-1);
        for(int i=2*v.size()-1;i>=0;i--){
            while(!st.empty() && v[st.top()]<=v[i%n]) st.pop();
            if (i < n) {
                if (!st.empty()) ans[i]=v[st.top()];
            }
            st.push(i%n);
        }
        return ans;
    }
};