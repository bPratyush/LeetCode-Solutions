class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        effort[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto [curreffort, r, c] = pq.top();
            pq.pop();
            if (r == n - 1 && c == m - 1) return curreffort;
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int neweffort = max(curreffort, abs(heights[nrow][ncol] - heights[r][c]));
                    if (neweffort < effort[nrow][ncol]) {
                        effort[nrow][ncol] = neweffort;
                        pq.push({neweffort, nrow, ncol});
                    }
                }
            }
        }
        return -1;
    }
};
