class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(), res=0;
        unordered_map<double,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double x1=points[j][0], x2=points[i][0];
                double y1=points[j][1], y2=points[i][1];
                if(y2==y1&&x2==x1) continue;
                else if(x2==x1) mpp[INT_MAX]++;
                else{
                    double slope=(y2-y1)/(x2-x1);
                    mpp[slope]++;
                }
            }
            int curmax=0;
            for(auto e:mpp) curmax=max(curmax,e.second);
            res=max(res,curmax);
            mpp.clear();
        }
        return res+1;
    }
};