class Solution {
public:
    bool wordPattern(string pattern, string s) {
    std::unordered_map<char, std::string> charToWord;
    std::unordered_map<std::string, char> wordToChar;

    std::vector<std::string> words;
    size_t start = 0;
    size_t end = 0;

    for (char c : pattern) {
        if (end >= s.length()) return false;

        while (end < s.length() && s[end] != ' ') {
            end++;
        }

        std::string word = s.substr(start, end - start);
        start = ++end;

        if (charToWord.find(c) == charToWord.end() && wordToChar.find(word) == wordToChar.end()) {
            charToWord[c] = word;
            wordToChar[word] = c;
        } else if (charToWord[c] != word || wordToChar[word] != c) {
            return false;
        }
    }

    return end >= s.length();
    }
};