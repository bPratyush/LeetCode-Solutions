class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }
    };

    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> occupiedIndices;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                occupiedIndices.push_back(i);
            }
        }
        for (int i = 1; i < occupiedIndices.size(); ++i) {
            int dist = (occupiedIndices[i] - occupiedIndices[i - 1]) / 2;
            pq.push({occupiedIndices[i - 1], dist});
        }
        int maxDist = 0;
        maxDist = max(occupiedIndices[0], n - 1 - occupiedIndices.back());
        while (!pq.empty()) {
            auto [index, dist] = pq.top();
            pq.pop();
            maxDist = max(maxDist, dist);
        }
        return maxDist;
    }
};