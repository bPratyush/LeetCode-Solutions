class Solution {
public:
    double binexp(double base, int exp) {
        double ans = 1.0;
        while (exp) {
            if (exp & 1) ans *= base;
            base*=base;
            exp >>=1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        return (n < 0) ? 1.0 / binexp(x, -n) : binexp(x, n);
    }
};
