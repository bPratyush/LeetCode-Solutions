class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,res=0,n=chars.size();
        while(i<n){
            int grplen=1;
            while(i+grplen<n&&chars[i+grplen]==chars[i]) grplen++;
            chars[res++]=chars[i];
            if(grplen>1){
                for(char c:to_string(grplen)) chars[res++]=c;
            }
            i+=grplen;
        }
        return res;
    }
};