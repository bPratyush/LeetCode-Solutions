class Solution {
public:
    bool checkValidString(string s) {
        int oc=0, cc=0;
        int n=s.length()-1;
        for(int i=0;i<=n;i++){
            if(s[i]=='('||s[i]=='*') oc++;
            else oc--; 
            if(s[n-i]==')'||s[n-i]=='*') cc++;
            else cc--;
        if(oc<0||cc<0) return false;
        }
                return true;
    }
};
