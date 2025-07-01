/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mpp;
        Node* ans=new Node(node->val, {});
        mpp[node]=ans;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* u=q.front();
            q.pop();
            vector<Node*> nh=u->neighbors;
            for(auto x:nh){
                if(mpp.find(x)==mpp.end()){
                    mpp[x]=new Node(x->val, {});
                    q.push(x);
                }
                mpp[u]->neighbors.push_back(mpp[x]);
            }
        }
        return ans;
    }
};