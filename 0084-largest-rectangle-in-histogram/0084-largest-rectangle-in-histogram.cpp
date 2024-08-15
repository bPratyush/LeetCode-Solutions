class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        A.push_back(0);
        int n=A.size(),res=0;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size()&&A[i]<=A[s.top()]){
                int height=A[s.top()];
                s.pop();
                int left=s.size()?s.top():-1;
                res=max(res,(i-left-1)*height);
            }
            s.push(i);
        }
        return res;
    }
};
