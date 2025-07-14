class Solution {
public:
    unordered_map<int,vector<char>>phone;
        Solution() {
        phone[1] = {};
        phone[2] = {'a', 'b', 'c'};
        phone[3] = {'d', 'e', 'f'};
        phone[4] = {'g', 'h', 'i'};
        phone[5] = {'j', 'k', 'l'};
        phone[6] = {'m', 'n', 'o'};
        phone[7] = {'p', 'q', 'r', 's'};
        phone[8] = {'t', 'u', 'v'};
        phone[9] = {'w', 'x', 'y', 'z'};
    }
    void backtrack(vector<string>&res, string digi, string curr){
        if(digi==""){
            res.push_back(curr); return;
        }
        char c=digi[0];
        if(c!='1'){
            for(char l:phone[c-'0']){
                curr+=l;
                backtrack(res,digi.substr(1,digi.size()-1),curr);
                curr.pop_back();
            }
        }
        else backtrack(res,digi.substr(1,digi.size()-1),curr);
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> res;
        backtrack(res,digits,"");
        return res;
    }
};