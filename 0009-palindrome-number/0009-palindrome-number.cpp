class Solution {
public:
int stringrev(int x) {
    int r = 0;
    while (x != 0) {
        if (r > (INT_MAX - x % 10) / 10) return 0;
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

bool isPalindrome(int x) {
    if (x < 0) return false;
    return x == stringrev(x);
}
};