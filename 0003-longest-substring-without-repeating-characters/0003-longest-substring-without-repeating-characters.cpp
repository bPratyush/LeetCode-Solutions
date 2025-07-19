class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,res=0;
        unordered_map<int,int>freq;
        for(;j<s.size();j++){
            freq[s[j]]++;
            while(freq[s[j]]>1){
                freq[s[i]]--;
                i++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};
