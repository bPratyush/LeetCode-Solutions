class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;  
        if (n == 1) return 10;
        int ans = 10; // 10 for n=1
        int uniqueDigits = 9;  // Start with 9 options for the first digits
        int availableDigits = 9; // 9 remaining digits to choose from
        for (int i = 2; i <= n; ++i) {
            uniqueDigits *= availableDigits;
            ans += uniqueDigits;
            availableDigits--;
        }
        return ans;
    }
};