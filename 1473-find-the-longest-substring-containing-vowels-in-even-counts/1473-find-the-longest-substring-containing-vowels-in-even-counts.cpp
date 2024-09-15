class Solution {
public:
    int findTheLongestSubstring(string s) {
       int prexor=0;
       unordered_map<char,int> hash;
       hash['a']=1; hash['e']=2; hash['i']=4, hash['o']=8, hash['u']=16;
       vector<int> mpp(32,-1);
       mpp[0]=0;
       int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (hash.find(s[i]) != hash.end()) prexor ^= hash[s[i]];
            if (mpp[prexor] == -1) mpp[prexor] = i + 1;
            res = max(res, i + 1 - mpp[prexor]);
        }
        return res;
    }
};