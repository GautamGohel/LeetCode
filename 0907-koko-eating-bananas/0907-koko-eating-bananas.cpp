#include <vector>
#include <algorithm>

class Solution {
public:
    bool ispossible(const std::vector<int>& piles, int mid, int h) {
        long long cnt = 0;
        for (int pile : piles) {
            cnt += (pile + mid - 1) / mid;  // Ceiling division using integer math
            if (cnt > h) return false;  // Early exit if count exceeds allowed hours
        }
        return true;
    }
    
    int minEatingSpeed(std::vector<int>& piles, int hour) {
        int l = 1, h = *max_element(piles.begin(), piles.end());
        while (l <= h) {
            int mid = l + (h - l) / 2;  // Avoid potential overflow
            if (ispossible(piles, mid, hour)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
