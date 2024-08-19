class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = (l+r) / 2;
            if (canEatAll(piles, h, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool canEatAll(vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) hours += (pile + k - 1) / k; 
        return hours <= h;
    }
};
