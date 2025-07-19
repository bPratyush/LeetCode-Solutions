class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        for(char c:t) freq[c]++;
        int counter=t.size(),b=0,e=0,d=INT_MAX,head=0;
        while(e<s.size()){
            if(freq[s[e++]]-- > 0) counter--;
            while(counter==0){
                if(e-b<d){
                    head=b;
                    d=e-head;
                }
                if(!freq[s[b++]]++) counter++;
            }
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};