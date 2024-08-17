class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mpp;
        string res="";
        for (char c:s) mpp[c]++;
        for (char c:s) {
            mpp[c]--;
            if (res.find(c) != string::npos) continue;
            while (!res.empty() && c < res.back() && mpp[res.back()] > 0)
            res.pop_back();
            res.push_back(c);
        }
        return res;
    }
};
