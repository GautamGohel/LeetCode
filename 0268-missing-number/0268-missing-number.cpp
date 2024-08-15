class Solution {
public:
    // int missingNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         bool flag=false;
    //         for(int j=0;j<n;j++){
    //             if(nums[j]==i){
    //                 flag=true;
    //             }
    //         }
    //         if(flag==false) return i;
    //     }
    //     return n;
    // }

    // int missingNumber(vector<int>& nums) {
    //    int n=nums.size();
    //    vector<int>hash(n+1,0);
    //    for(int i=0;i<n;i++){
    //        hash[nums[i]]++;
    //    }
    //    for(int i=0;i<=n;i++){
    //       if(hash[i]==0){
    //         return i;
    //       }
    //    }
    //    return n;
    // }

    //  int missingNumber(vector<int>& nums) {
    //    int n=nums.size();
    //    int sum=n*(n+1)/2;
    //    int s=0;
    //    for(int i=0;i<n;i++){
    //      s+=nums[i];
    //    }
    //    return sum-s;
    //  }

    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int x=0;
       for(int i=0;i<=n;i++){
           x=x^i;
       }
       for(int i=0;i<n;i++){
          x=x^nums[i];
       }
       return x;
     }
};