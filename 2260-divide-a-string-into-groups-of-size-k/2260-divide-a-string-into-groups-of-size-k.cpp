class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n=s.size(), i=0;
        while (i < n) {
            string temp = "";
            for (int j = 0; j < k; j++) {
                if (i < n) temp += s[i++];
                else temp += fill;
            }
            res.push_back(temp);
        }
        return res;
    }
};
