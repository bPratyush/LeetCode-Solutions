class Solution {
public:
    vector<int> left(vector<int>& heights) {
        vector<int> left;
        stack<pair<int, int>> sleft;
        int n = heights.size();
        int pseudo = -1;
        for (int i = 0; i < n; i++) {
            while (!sleft.empty() && sleft.top().first >= heights[i]) {
                sleft.pop();
            }
            if (sleft.empty()) {
                left.push_back(pseudo);
            } else {
                left.push_back(sleft.top().second);
            }
            sleft.push({heights[i], i});
        }
        return left;
    }

    vector<int> right(vector<int>& heights) {
        vector<int> right;
        stack<pair<int, int>> sright;
        int n = heights.size();
        int pseudo = n;
        for (int i = n - 1; i >= 0; i--) {
            while (!sright.empty() && sright.top().first >= heights[i]) {
                sright.pop();
            }
            if (sright.empty()) {
                right.push_back(pseudo);
            } else {
                right.push_back(sright.top().second);
            }
            sright.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        return right;
    }

    int MAH(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_bound = left(heights);
        vector<int> right_bound = right(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right_bound[i] - left_bound[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int mx = MAH(heights);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] += matrix[i][j] - '0';
                }
            }
            mx = max(mx, MAH(heights));
        }
        return mx;
    }
};
