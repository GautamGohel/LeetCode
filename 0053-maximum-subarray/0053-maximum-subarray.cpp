class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force O(n2)
        // int n=nums.size();
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //    for(int j=i;j<n;j++){
        //       sum+=nums[j];
        //       maxi=max(maxi,sum);
        //    }
        // }
        // return maxi;

        //kadane's algorithm

        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>maxi)
            maxi=sum;
            if(sum<=0){
                sum=0;
            }
        }
        return maxi;
    }
};