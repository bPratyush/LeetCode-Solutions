#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (u != parent[u]) {
            parent[u] = findParent(parent[u]);  // Path compression
        }
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
                rank[rootU]++;
            }
        }
    }

    int getSize(int u) {
        return size[findParent(u)];
    }
};

class Solution {
public:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Union all adjacent 1s
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; ++k) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                            ds.unionByRank(i * n + j, nr * n + nc);
                        }
                    }
                }
            }
        }

        // Find the largest island that can be formed by flipping one 0
        int maxIslandSize = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> components;
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; ++k) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                            components.insert(ds.findParent(nr * n + nc));
                        }
                    }
                    int sizeSum = 1;  // Include the current cell that will be flipped to 1
                    for (int comp : components) {
                        sizeSum += ds.getSize(comp);
                    }
                    maxIslandSize = max(maxIslandSize, sizeSum);
                }
            }
        }

        // If no 0 exists, then the largest island is the size of any component
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    maxIslandSize = max(maxIslandSize, ds.getSize(i * n + j));
                }
            }
        }

        return maxIslandSize;
    }
};
