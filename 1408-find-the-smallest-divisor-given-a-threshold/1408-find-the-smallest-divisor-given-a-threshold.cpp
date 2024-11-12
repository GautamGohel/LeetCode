class Solution {
public:

    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        if(n>threshold) return -1;
        while(l<=h){
            int cnt=0;
            int mid=(l+h)/2;
            for(int i=0;i<n;i++){
                cnt+=ceil((float)nums[i]/(float)mid);
            }
            if(cnt<=threshold){
               h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};