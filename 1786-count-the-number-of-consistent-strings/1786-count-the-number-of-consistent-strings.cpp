class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<int> allowset;
        for(int i=0;i<allowed.size();i++) allowset.insert(allowed[i]);
        int cnt=0;
        for(string w:words){
            bool cnt1=true;
            for(int i=0;i<w.length();i++){
                char c=w[i];
                if(allowset.find(c)==allowset.end()){
                    cnt1=false;
                    break;
                }
            }
            if(cnt1) cnt++;
        }
        return cnt;
    }
};