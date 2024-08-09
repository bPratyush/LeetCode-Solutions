class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        unordered_map<int, int> freq_map;
        int cnt = 0;
        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();
            int complement = k - a;
            if (freq_map[complement] > 0) {
                freq_map[complement]--;
                cnt++;
            }
            else freq_map[a]++;
        }
        return cnt;
    }
};