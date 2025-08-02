class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq1, freq2, totalFreq;
    for (int fruit : basket1) freq1[fruit]++;
    for (int fruit : basket2) freq2[fruit]++;
    for (auto&[fruit,cnt]:freq1) totalFreq[fruit]+=cnt;
    for (auto&[fruit,cnt]:freq2) totalFreq[fruit]+=cnt;
    for (auto& [fruit, cnt] : totalFreq)
        if (cnt % 2 != 0) return -1;
    vector<int> extra1, extra2;
    for (auto& [fruit, total] : totalFreq) {
        int diff = freq1[fruit] - freq2[fruit];
        if(diff>0) extra1.insert(extra1.end(),diff/2, fruit);
        if (diff < 0) extra2.insert(extra2.end(), -diff / 2, fruit);
    }
    sort(extra1.begin(), extra1.end());
    sort(extra2.rbegin(), extra2.rend());
    int minCost = INT_MAX;
    for(int fruit:basket1) minCost=min(minCost, fruit);
    for(int fruit:basket2) minCost=min(minCost, fruit);
    long long totalCost = 0;
    for (int i = 0; i < extra1.size(); ++i) {
        int a = extra1[i], b = extra2[i];
        totalCost += min({a, b, 2 * minCost});
    }
    return totalCost;
    }
};