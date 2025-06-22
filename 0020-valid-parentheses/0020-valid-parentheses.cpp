class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c=='('||c=='{'||c=='[') st.push(c);
            else if(c==')'||c=='}'|c==']'){
                if(st.empty()) return false;
                char tp=st.top();
                if(c==')'&&tp!='('||c=='}'&&tp!='{'||c==']'&&tp!='[') return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};