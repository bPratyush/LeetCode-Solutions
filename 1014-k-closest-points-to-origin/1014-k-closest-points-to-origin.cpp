class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue< pair<int , pair<int,int>> >pq;
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            int x = points[i][0] , y = points[i][1];
            int distance = (x * x) + (y * y);
            if(!pq.empty() && distance == pq.top().first && pq.size() >= k) pq.pop();
            pq.push({distance,{x,y}});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            vector<int>point = {x,y};
            result.push_back(point);
        }
        return result;
    }
};