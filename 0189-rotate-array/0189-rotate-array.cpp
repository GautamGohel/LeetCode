class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int>temp(n);
    //     int j=n-k;
    //     for(int i=0;i<n;i++){
    //        temp[i]=nums[j%n];
    //        j++;
    //     }
    //     nums=temp;
    // }

    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};