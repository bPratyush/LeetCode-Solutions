class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string r1="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#') r1.push_back(s[i]);
            else if(!r1.empty()) r1.pop_back();
        }
        string t1="";
        for(int i=0;i<t.size();i++){
            if(t[i]!='#') t1.push_back(t[i]);
            else if(!t1.empty()) t1.pop_back();
        }
        if(r1.size()!=t1.size()) return false;
        return r1==t1;
    }
};