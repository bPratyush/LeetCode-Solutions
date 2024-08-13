class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l=0,r=0,n=s.size(),res=INT_MIN;
       if(s=="") return 0;
       if(n==0) return 0;
       unordered_map<int,int>freq;
       for(;r<n;r++){
        freq[s[r]]++;
        while(freq[s[r]]>1){
            freq[s[l]]--;
            l++;
        }
        res=max(res,r-l+1);
       }
       return res;
    }
};
