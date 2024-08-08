class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        vector<int> indeg(numCourses, 0);
        for (auto& preq : prerequisites) {
            int course = preq[0];
            int prerequisite = preq[1];
            adj[prerequisite].push_back(course);
            indeg[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }
        if (res.size() == numCourses) return res;
        else return vector<int>{};
    }
};