class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
    int min_value = arrays[0].front();
        int max_value = arrays[0].back();
        int max_dist = 0;
        
        // Iterate through the rest of the arrays
        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate the distance using the current array's elements and global min/max
            max_dist = max(max_dist, abs(arrays[i].back() - min_value));
            max_dist = max(max_dist, abs(max_value - arrays[i].front()));
            
            // Update global min and max values
            min_value = min(min_value, arrays[i].front());
            max_value = max(max_value, arrays[i].back());
        }
        
        return max_dist;
    }
};