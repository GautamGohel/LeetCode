class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        /*
         int high=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(high<nums[i]){
                high=nums[i];
            }
        }
        for(int i=1;i<=high;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                sum += ceil((double)(nums[j]) / (double)(i));
            }
            if(sum<=threshold){
                return i;
            }
        }
        return -1;
        */
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(high<nums[i]){
                high=nums[i];
            }
        }
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            for(int i=0;i<nums.size();i++){
               sum+=ceil(double(nums[i])/double(mid));
            }
            if(sum>threshold){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};