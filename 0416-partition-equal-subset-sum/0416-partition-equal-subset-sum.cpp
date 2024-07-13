class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1, false);
        prev[0] = true;
        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }
        for (int i = 1; i < n; i++) {
            vector<bool> curr(k+1, false);
            curr[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTaken = prev[target];
                bool taken = false;
                if (target >= arr[i]) {
                    taken = prev[target - arr[i]];
                }
                curr[target] = taken || notTaken;
            }
            prev = curr;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        if (total % 2 != 0) return false;
        int target = total / 2;
        return subsetSumToK(nums.size(), target, nums);
    }
};
