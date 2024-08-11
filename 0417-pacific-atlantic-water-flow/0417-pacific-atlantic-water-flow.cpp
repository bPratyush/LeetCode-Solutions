class Solution {
public:
    void pacific_dfs(vector<vector<pair<int, pair<bool, bool>>>>& grid, int m, int n, int i, int j, int prev = 0)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j].second.first || grid[i][j].first < prev)
            return;

        grid[i][j].second.first = true;
        pacific_dfs(grid, m, n, i - 1, j, grid[i][j].first);
        pacific_dfs(grid, m, n, i + 1, j, grid[i][j].first);
        pacific_dfs(grid, m, n, i, j - 1, grid[i][j].first);
        pacific_dfs(grid, m, n, i, j + 1, grid[i][j].first);
    }

    void atlantic_dfs(vector<vector<pair<int, pair<bool, bool>>>>& grid, int m, int n, int i, int j, int prev = 0)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j].second.second || grid[i][j].first < prev)
            return;

        grid[i][j].second.second = true;
        atlantic_dfs(grid, m, n, i - 1, j, grid[i][j].first);
        atlantic_dfs(grid, m, n, i + 1, j, grid[i][j].first);
        atlantic_dfs(grid, m, n, i, j - 1, grid[i][j].first);
        atlantic_dfs(grid, m, n, i, j + 1, grid[i][j].first);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<pair<int, pair<bool, bool>>>> grid(m, vector<pair<int, pair<bool, bool>>>(n));
        vector<vector<int>> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = {matrix[i][j], {false, false}};
            }
        }

        for (int j = 0; j < n; j++) {
            pacific_dfs(grid, m, n, 0, j);
            atlantic_dfs(grid, m, n, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            pacific_dfs(grid, m, n, i, 0);
            atlantic_dfs(grid, m, n, i, n - 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool pacific = grid[i][j].second.first;
                bool atlantic = grid[i][j].second.second;

                if (pacific && atlantic)
                    result.push_back({i, j});
            }
        }

        return result;
    }
};