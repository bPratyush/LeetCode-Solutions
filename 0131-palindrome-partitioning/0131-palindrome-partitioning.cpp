class Solution {
public:
    bool isPalindrome(string& str, int i, int j){
        while(i < j){
            if(str[i++] != str[j--]) return 0;
        }
        return 1;
    }
    
    void MCM(string& str, int i, int j, vector<string> vect, vector<vector<string>>& res){
        if(i > j){
            if(!vect.empty()) res.push_back(vect);
        }
        for(int k = i; k <= j; k++){
            if(isPalindrome(str, i, k)){
                vect.push_back(str.substr(i, (k-i+1)));
                MCM(str, k+1, j, vect, res);
                vect.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        MCM(s, 0, s.size()-1, temp, res);
        return res;
    }
};