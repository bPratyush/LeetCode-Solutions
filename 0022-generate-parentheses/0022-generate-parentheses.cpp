class Solution {
public:
    void helper(vector<string> &ans, int open, int close, string& curr, int n)
    {
        if(curr.length()==2*n) {ans.push_back(curr); return;}
        if(open<n){
            curr.push_back('(');
            helper(ans,open+1,close,curr,n);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            helper(ans,open,close+1,curr,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        if(n==0) return ans;
        string temp="";
        helper(ans,open,close,temp,n);
        return ans;
    }
};