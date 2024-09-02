class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0, n=chalk.size();
        for(int i=0;i<n;i++){
            sum+=chalk[i];
            if(sum>k) break;
        }
        k%=sum;
        for(int i=0;i<n;i++){
            if(k<chalk[i]) return i;
            k-=chalk[i];
        }
        return 0;
    }
};