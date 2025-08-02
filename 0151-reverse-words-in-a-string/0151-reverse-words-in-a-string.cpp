class Solution {
public:
    string reverseWords(string s) {
        string res="",word="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    res+=word+" ";
                    word="";
                }
            }
            else word+=s[i];
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());
            res+=word;
        }  
        if(!res.empty()&&res.back()==' ') res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};