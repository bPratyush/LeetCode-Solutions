class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int N = answerKey.length();
        int i = 0, j = 0, maxLen = 0, maxCount = 0;
        vector<int> count(2, 0); // count[0] for 'F', count[1] for 'T'
        for (; j < N; ++j) {
            maxCount = max(maxCount, ++count[answerKey[j] == 'T']);
            if ((j - i + 1) - maxCount > k) {
                --count[answerKey[i] == 'T'];
                ++i;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};