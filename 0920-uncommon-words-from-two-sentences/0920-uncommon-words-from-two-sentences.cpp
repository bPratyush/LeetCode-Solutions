class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        stringstream ssA(s1), ssB(s2);
        string word;
        while (ssA >> word) count[word]++;
        while (ssB >> word) count[word]++;
        vector<string> ans;
        for (auto& entry : count) {
            if (entry.second == 1) ans.push_back(entry.first);
        }
        return ans;
    }
};