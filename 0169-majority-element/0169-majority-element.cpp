class Solution {
public:
    int majorityElement(vector<int>& nums) {
    // brute force two for loops     
    //    int n=nums.size();
    //    for(int i=0;i<n;i++){
    //       int cnt=0;
    //       int val=nums[i];
    //       for(int j=i+1;j<n;j++){
    //         if(val==nums[j]) cnt++;
    //         if(cnt>=n/2) return val;
    //       }
    //    }
    //    return -1;

        // better approach O(nlogn+m) sc O(n) 
        // unordered_map<int, int> mp; 
        // int n = nums.size() / 2; 
        // for (auto a : nums) {
        //     mp[a]++;
        // }
        // int ans = 0; 
        // for (auto a : mp) {
        //     if (a.second > n) {
        //         ans = a.first; 
        //         break;
        //     }
        // }
        // return ans; 

       //moore's voting algorithm
       //tc O(n) sc O(1)

       int n=nums.size();
       int ele=nums[0];
       int cnt=0;
        for(int i=0;i<n;i++){
           if(nums[i]==ele){
             cnt++;
           }else{
            cnt--;
           }
           if(cnt==0){
             ele=nums[i];
             cnt=1;
           }
        }
        return ele;
    }
};


