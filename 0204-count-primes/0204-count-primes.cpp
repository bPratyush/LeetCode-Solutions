class Solution {
public:
    vector<bool>prime;
    int count;
    void sieve(int n){
        for(int p=2;p*p<=n;p++){
            if(prime[p]==true){
                for(int i=p*p;i<n;i+=p){
                    prime[i]=false;
                }
            }
        }
        for(int i=2;i<n;i++){
            if(prime[i]==true) count++;
        }
    }
    int countPrimes(int n) {
        prime = vector<bool>(n, true);
        count = 0;
        if (n < 3) return 0; 
        sieve(n);
        return count;
    }
};