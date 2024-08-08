#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen; // To detect cycles

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
};
