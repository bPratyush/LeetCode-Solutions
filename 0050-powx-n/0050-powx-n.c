double pow2(double x, long n) {
    if(n < 0) {
        n = -n;
        x = 1/x;
    }
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n % 2 == 0) return pow2(x * x, n/2);
    else return x * pow2(x * x, (n - 1)/2);
}

double myPow(double x, int n) {
    long N = n;
    return pow2(x, N);
}