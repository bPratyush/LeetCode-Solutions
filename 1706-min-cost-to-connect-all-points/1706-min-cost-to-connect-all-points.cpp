class Solution {
public:
    vector<int> parent, size;
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    struct Edge {
        int u, v, weight;
        bool operator<(const Edge &other) const {
            return weight < other.weight;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, distance});
            }
        }
        int cost = 0;
        vector<Edge> result;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
        sort(edges.begin(), edges.end());
        for (Edge e : edges) {
            if (find_set(e.u) != find_set(e.v)) {
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }
        return cost;
    }
};
