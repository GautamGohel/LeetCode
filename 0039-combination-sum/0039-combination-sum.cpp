class Solution {
public:
    void getallsubsets(int i, vector<int>& arr, int n, int sum, vector<int>& ans, vector<vector<int>>& ds, int target) {
        if (sum == target) {
            ds.push_back(ans); 
            return;
        }
        if (i == n || sum > target) {
            return; 
        }
        ans.push_back(arr[i]);
        getallsubsets(i, arr, n, sum + arr[i], ans, ds, target);
        ans.pop_back(); 
        getallsubsets(i + 1, arr, n, sum, ans, ds, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ds; 
        vector<int> ans;        
        int n = candidates.size();

        getallsubsets(0, candidates, n, 0, ans, ds, target);
        return ds;
    }
};
