class Solution {
public:
    static bool cmp(string&a,string&b){
        return a+b>b+a;
    }
    string largestNumber(vector<int> &nums) {
        vector<string> strNums(nums.size());
        for (int i = 0; i < nums.size(); ++i) strNums[i] = to_string(nums[i]);
        sort(strNums.begin(), strNums.end(), cmp);
        if (strNums[0] == "0") return "0";
        string largestNumberStr;
        for (string numAsStr : strNums) largestNumberStr += numAsStr;
        return largestNumberStr;
    }
};