class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0) return res;
        int l = 0, t = 0, r = n - 1, b = m - 1;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]);
            t++;
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]);
            r--;
            if (t <= b) {
                for (int i = r; i >= l; i--) res.push_back(matrix[b][i]);
                b--;
            }
            if (l <= r) {
                for (int i = b; i >= t; i--) res.push_back(matrix[i][l]);
                l++;
            }
        }
        return res;
    }
};
