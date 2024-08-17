class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adjList;
        // Create a map from the bus stop to all the routes including this stop.
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adjList[stop].push_back(route);
            }
        }

        queue<int> q;
        unordered_set<int> visited;
        // Insert all the routes in the queue that have the source stop.
        for (auto route : adjList[source]) {
            q.push(route);
            visited.insert(route);
        }

        int busCount = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int currentRoute = q.front();
                q.pop();

                // Iterate over the stops in the current route.
                for (auto stop : routes[currentRoute]) {
                    if (stop == target) {
                        return busCount;
                    }

                // Iterate over the next possible routes from the current stop.
                    for (auto nextRoute : adjList[stop]) {
                        if (!visited.count(nextRoute)) {
                            visited.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};
