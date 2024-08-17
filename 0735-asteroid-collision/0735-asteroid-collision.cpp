class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> Stack;
        for(int asteroid: asteroids) {
            bool destroyed = false;
            while(!Stack.empty() && asteroid < 0 && Stack.top() > 0) {
               if(-asteroid == Stack.top()) {
                   destroyed = true;
                   Stack.pop();
                   break;
               }
               else if(-asteroid > Stack.top()) {
                   Stack.pop();
               }
               else {
                   destroyed = true;
                   break;
               }
           }
            if(!destroyed)
            Stack.push(asteroid);
        }
        vector<int> result(Stack.size());
        for(int i = Stack.size() - 1; i >= 0; i--) {
            result[i] = Stack.top();
            Stack.pop();
        }
        return result;
    }
};