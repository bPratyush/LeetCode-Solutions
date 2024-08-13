class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        vector<vector<bool>> mat(lenS + 1, vector<bool>(lenP + 1, false));

        mat[0][0] = true;

        for (int i = 1; i <= lenP; i++) {
            if (p[i - 1] == '*') {
                mat[0][i] = mat[0][i - 2];
            }
        }

        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenP; j++) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    mat[i][j] = mat[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    mat[i][j] = mat[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        mat[i][j] = mat[i][j] || mat[i - 1][j];
                    }
                } else {
                    mat[i][j] = false;
                }
            }
        }

        return mat[lenS][lenP];
    }
};