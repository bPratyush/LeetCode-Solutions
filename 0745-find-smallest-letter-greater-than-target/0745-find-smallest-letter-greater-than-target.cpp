class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,r=letters.size()-1;
        int ceilidx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(letters[mid]<=target) l=mid+1;
            else{
                ceilidx=mid;
                r=mid-1;
            }
        }
        return (ceilidx != -1) ? letters[ceilidx] : letters[0];
    }
};