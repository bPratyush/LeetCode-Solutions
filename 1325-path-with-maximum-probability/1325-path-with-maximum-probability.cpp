class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double, pair<int, int>>> ed;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            ed.emplace_back(prob, make_pair(u, v));
        }
        unordered_map<int, vector<pair<int, double>>> graph;
        for (const auto& e : ed) {
            double prob = e.first;
            int u = e.second.first;
            int v = e.second.second;
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob); 
        }
        priority_queue<pair<double, int>> pq;
        vector<double> probabilities(n, 0.0);
        pq.emplace(1.0, start_node);
        probabilities[start_node] = 1.0;
        while (!pq.empty()) {
            double current_prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == end_node) return current_prob;
            for (auto neighbor : graph[node]) {
                int next_node = neighbor.first;
                double edge_prob = neighbor.second;
                double new_prob = current_prob*edge_prob;
                if (new_prob > probabilities[next_node]) {
                    probabilities[next_node] = new_prob;
                    pq.emplace(new_prob, next_node);
                }
            }
        }
        return 0.0;
    }
};