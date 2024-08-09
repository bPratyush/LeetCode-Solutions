class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] - M - 1 < k) L = M + 1;
            else R = M - 1;
        }
        return L + k;
    }
};