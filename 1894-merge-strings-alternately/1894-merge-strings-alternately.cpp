class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,n=word1.size(),m=word2.size();
        string res="";
        while(i<n&&j<m){
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while(i<n) res.push_back(word1[i++]);
        while(j<m) res.push_back(word2[j++]);
        return res;
    }
};