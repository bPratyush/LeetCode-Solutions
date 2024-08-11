class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0, n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int lastStart = intervals[0][0], lastEnd = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < lastEnd){
                count++;
                lastEnd = min(lastEnd, intervals[i][1]);
            }
            else{
                lastEnd = intervals[i][1];
                lastStart = intervals[i][0];
            }
        }

        return count;
    }
};