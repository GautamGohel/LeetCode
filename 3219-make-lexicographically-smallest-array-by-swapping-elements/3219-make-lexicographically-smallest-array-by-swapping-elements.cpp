class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
            int n = nums.size();
    vector<pair<int, int>> indexedNums;
    
    for (int i = 0; i < n; ++i) {
        indexedNums.emplace_back(nums[i], i);
    }
    
    sort(indexedNums.begin(), indexedNums.end());
    
    vector<int> result(n);
    int i = 0;
    
    while (i < n) {
        int j = i;
        while (j + 1 < n && indexedNums[j + 1].first - indexedNums[j].first <= limit) {
            ++j;
        }
        
        vector<int> indices;
        for (int k = i; k <= j; ++k) {
            indices.push_back(indexedNums[k].second);
        }
        
        sort(indices.begin(), indices.end());
        
        for (int k = i; k <= j; ++k) {
            result[indices[k - i]] = indexedNums[k].first;
        }
        
        i = j + 1;
    }
    
    return result;
    }
};