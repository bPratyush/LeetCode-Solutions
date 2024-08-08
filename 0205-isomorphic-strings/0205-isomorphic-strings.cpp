class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char m1[260], m2[260];
        for (int i = 0; i < s.size(); ++i) {
            if(m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = m2[t[i]] = i + 1;
        }
        return true;
    }
};