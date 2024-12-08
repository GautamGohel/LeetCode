class Solution {
public:

    void getallcombinations(int i,int n,vector<int>candidates,int target,vector<int>&arr,vector<vector<int>>&ds){
        if(target==0){
            ds.push_back(arr);
            return;
        }
       for(int ind=i;ind<n;ind++){
           if(ind>i and candidates[ind]==candidates[ind-1]) continue;
           if(candidates[ind]>target) break;
           arr.push_back(candidates[ind]);
           getallcombinations(ind+1,n,candidates,target-candidates[ind],arr,ds);
           arr.pop_back();
       }
    }
   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>arr;
        vector<vector<int>>ds;
        sort(candidates.begin(),candidates.end());
        getallcombinations(0,n,candidates,target,arr,ds);
        return ds;
    }
};