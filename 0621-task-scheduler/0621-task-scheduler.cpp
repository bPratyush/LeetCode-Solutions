class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        priority_queue<int>pq;
        for(char c:tasks) freq[c]++;
        for (auto& p : freq) {
            pq.push(p.second);
        }
        int tm=0;
        while(!pq.empty()){
            int cyc=n+1;
            vector<int>vec;
            int cnt=0;
            while(cyc-- && !pq.empty()){
                if(pq.top()>1) vec.push_back(pq.top()-1);
                pq.pop();
                cnt++;
            }
            for(int &x:vec) pq.push(x);
            tm+=(pq.empty()?cnt:n+1);
        }
        return tm;
    }
};