class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<long long> prevrow(m);
        for (int i = 0; i < m; i++) prevrow[i] = points[0][i];
        for (int i = 1; i < n; i++) {
            vector<long long> lmax(m);
            vector<long long> rmax(m);
            vector<long long> currow(m);
            lmax[0] = prevrow[0];
            for (int j = 1; j < m; j++) lmax[j] = max(lmax[j-1] - 1, prevrow[j]);
            rmax[m-1] = prevrow[m-1];
            for (int j = m - 2; j >= 0; j--) rmax[j] = max(rmax[j+1] - 1, prevrow[j]);
            for (int j = 0; j < m; j++) currow[j] = points[i][j] + max(lmax[j], rmax[j]);
            prevrow = currow;
        }  
        long long res = 0;
        for (int j = 0; j < m; j++) res = max(res, prevrow[j]);
        return res;
    }
};