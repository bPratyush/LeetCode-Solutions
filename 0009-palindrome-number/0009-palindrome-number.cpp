class Solution {
public:
bool isPalindrome(int x) {
    if(x<0) return false;
    int revx=0, origx=x;
    while(x){
        if(revx>(INT_MAX-x%10)/10) return 0;
        revx=revx*10+x%10;
        x/=10;
    }
    return origx==revx;
    }
};