class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(), i=0;
        sort(citations.begin(), citations.end());
        while (i < n && citations[n - 1 - i] > i) i++;
        return i;
    }
};
