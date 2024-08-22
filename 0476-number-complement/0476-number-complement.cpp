class Solution {
public:
    int findComplement(int num) {
        string res = "";
        while (num){
            res += to_string((num % 2) ^ 1);
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return stoi(res, nullptr, 2);
    }
};