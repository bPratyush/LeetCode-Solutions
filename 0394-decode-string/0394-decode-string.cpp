class Solution {
    int i=0;
    string Decode(string &s){
        string res="";
        while(i<s.length() && s[i]>='a' && s[i]<='z' && s[i]!=']')
        res.push_back(s[i++]);
        if(i>=s.length() || s[i]==']')
        return res;
        string num="";
        while(s[i] != '[' )
        num.push_back(s[i++]);
        int n = stoi(num) ;
        i++;
        string rep = Decode(s);
        for(int k = 0 ; k< n ; k++)
        res+=rep;
        i++;
        return res+Decode(s);
    }
public:
    string decodeString(string s) {
        return Decode(s);  
    }
};