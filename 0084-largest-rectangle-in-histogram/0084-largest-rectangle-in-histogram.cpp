class Solution {
public:
    vector<int> NSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> PSE(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = NSE(heights), pse = PSE(heights);
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1; // Width of the largest rectangle with heights[i] as the smallest height
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};