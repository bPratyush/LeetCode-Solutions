class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mpp(128,0);
        for(char c:t) mpp[c]++;
        int counter=t.size(), b=0, e=0, d=INT_MAX, head=0;
        while(e<s.size()){
            if(mpp[s[e++]]-->0) counter--;
            while(counter==0){
                if(e-b<d){
                    head=b;
                    d=e-head;
                }
                if(mpp[s[b++]]++==0) counter++;
            }
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};