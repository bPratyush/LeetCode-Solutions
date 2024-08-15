class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int>count;
        for(int i = 0  ; i < magazine.length() ; i++) count[magazine[i]]++;
        for (int i = 0; i < ransomNote.length(); i++) {
            count[ransomNote[i]]--;
            if (count[ransomNote[i]] < 0) return false;
        }
        return true;
    }
};