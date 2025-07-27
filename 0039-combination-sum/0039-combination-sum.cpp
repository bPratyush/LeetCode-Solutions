class Solution {
public:
void bt(int idx,vector<int>&cand,int target,vector<vector<int>>&res,vector<int>&op){
    if(target==0){
        res.push_back(op);
        return;
    }
    for(int i=idx;i<cand.size();i++){
        if(cand[i]<=target){
            op.push_back(cand[i]);
            bt(i,cand,target-cand[i],res,op);
            op.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>op;
    bt(0,candidates,target,res,op);
    return res;
    }
};