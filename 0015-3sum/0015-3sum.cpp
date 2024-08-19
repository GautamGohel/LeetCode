class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n=nums.size();
    //     set<vector<int>>st;
    //     for(int i=0;i<n;i++){
    //         set<int>hashset;
    //         for(int j=i+1;j<n;j++){
    //             int third=-(nums[i]+nums[j]);
    //             if(hashset.find(third)!=hashset.end()){
    //                 vector<int>ans={nums[i],nums[j],third};
    //                 sort(ans.begin(),ans.end());
    //                 st.insert(ans);
    //             }
    //             hashset.insert(nums[j]);
    //         }
    //     }
    //     vector<vector<int>>ans(st.begin(),st.end());
    //     return ans;
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>finans;
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
                int j=i+1;
                int k=n-1;
                while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    finans.push_back(temp);
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1]) j++;
                    while(j<k and nums[k]==nums[k+1]) k--;
                }}
        }
        return finans;
    }
};