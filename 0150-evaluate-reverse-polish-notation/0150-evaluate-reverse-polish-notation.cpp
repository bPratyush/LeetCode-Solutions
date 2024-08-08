class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        map<string, function<int(int, int)>> m = {
            {"+", plus<int>()},
            {"-", minus<int>()},
            {"*", multiplies<int>()},
            {"/", divides<int>()}
        };

        for (auto str : tokens) {
            if (m.find(str) == m.end()) {
                stck.push(stoi(str));
            } else {
                int s1 = stck.top();
                stck.pop();
                int s2 = stck.top();
                stck.pop();

                stck.push(m[str](s2, s1));
            }
        }

        return stck.top();
    }
};
