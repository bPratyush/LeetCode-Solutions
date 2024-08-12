class KthLargest {
    int K;
    priority_queue<int,vector<int>,greater<int>> pq;

public: 
    KthLargest(int k, vector<int>& v): K(k), pq(v.begin(),v.end()){
        while(pq.size()>K)pq.pop();
    }
    int add(int x) {    
        pq.push(x);
        if(pq.size()>K)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */