class Solution {
public:
    int getLucky(string s, int k) {
        string res="";
        for(char c:s) res+=to_string(c-'a'+1);
        while(k-->0){
            int sum=0;
            for(char digit:res) sum+=digit-'0';
            res=to_string(sum);
        }
        return stoi(res);
    }
};