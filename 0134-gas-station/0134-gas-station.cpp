class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totgas=0,currgas=0,start=0;
        for(int i=0;i<n;i++){
            totgas+=gas[i]-cost[i];
            currgas+=gas[i]-cost[i];
            if(currgas<0){
                start=i+1;
                currgas=0;
            }
        }
        if(totgas<0) return -1;
        else return start;
    }
};