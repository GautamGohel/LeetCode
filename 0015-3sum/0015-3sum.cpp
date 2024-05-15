class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the input array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            // Use two-pointer technique to find pairs with sum -nums[i]
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate sum inside the while loop

                if (sum > 0) {
                    --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;

                    // Avoid duplicates for the second element
                    while (j < k && nums[j] == nums[j - 1]) ++j;

                    // Avoid duplicates for the third element
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }

        return ans;
    }
};

 /*
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
        */
        /*
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int>hash;
          for(int j=i+1;j<n;j++){
            int k=-(nums[i]+nums[j]);
            if(hash.find(k)!=hash.end()){
               vector<int>temp={nums[i],nums[j],k};
               sort(temp.begin(),temp.end());
               st.insert(temp);
            }
            hash.insert(nums[j]);
          }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
        */