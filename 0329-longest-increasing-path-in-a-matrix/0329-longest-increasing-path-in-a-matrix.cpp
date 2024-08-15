class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& vis, int i, int j) {
        if (vis[i][j] != 0) return vis[i][j];
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int longestPath = 1;
        for (int k = 0; k < 4; k++) {
            int newRow = i + drow[k];
            int newCol = j + dcol[k];
            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] > matrix[i][j]) {
                longestPath = max(longestPath, 1 + dfs(matrix, vis, newRow, newCol));
            }
        }
        vis[i][j] = longestPath;
        return longestPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int longestPath = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                longestPath = max(longestPath, dfs(matrix, vis, i, j));
            }
        }
        return longestPath;
    }
};

