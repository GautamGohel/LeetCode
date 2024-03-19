class Solution {
public:
   
   void findcombination(int i,vector<int>&a,int target,vector<vector<int>>&finalres,vector<int> ds){
     if(i==a.size()){
        if(target==0){
            finalres.push_back(ds);
        }
            return;
     }
     if(a[i]<=target){
     ds.push_back(a[i]);
     findcombination(i,a,target-a[i],finalres,ds);
     ds.pop_back();
     }
     findcombination(i+1,a,target,finalres,ds);
   }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>finalres;
        vector<int>ds;
        findcombination(0,candidates,target,finalres,ds);
        return finalres;
    }
};