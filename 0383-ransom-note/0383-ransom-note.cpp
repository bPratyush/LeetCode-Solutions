class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char c : ransomNote) {
            bool found = false;
            for (int i = 0; i < magazine.size(); i++) {
                if (magazine[i] == c) {
                    magazine.erase(i, 1);
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false; 
            }
        }
        return true;
    }
};
