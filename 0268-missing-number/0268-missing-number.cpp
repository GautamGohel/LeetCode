class Solution {
public:
    int missingNumber(vector<int>& arr) {
        //brute force O(n2)
        // for(int i=0;i<arr.size();i++){
        //     bool flag=false;
        //     for(int j=0;j<arr.size();j++){
        //         if(arr[j]==i){
        //             flag=true;
        //             break;
        //         }
        //     }
        //     if(flag==false) return i;
        // }
        // return arr.size();

        //better tc O(2n) sc O(n)
        // int n = nums.size();
        // vector<int>v(n+1,-1);
        // for(int i =0;i<nums.size();i++){
        //     v[nums[i]] = nums[i];
        // }
        // for(int i =0;i<v.size();i++){
        //     if(v[i]==-1)return i;
        // }
        // return 0;

        //optimal approch 1 tc O(n) sc O(1)
        // int n=arr.size();
        // int sum=n*(n+1)/2;
        // int arrsum=0;
        // for(int i=0;i<n;i++){
        //     arrsum+=arr[i];
        // }
        // return sum-arrsum;

        //optimal approach 2 bit manupulation
        int n=arr.size();
        int xor1=0, xor2=0;
        for(int i=0;i<n;i++){
          xor1=xor1^arr[i];
          xor2=xor2^(i+1);
        }
       return xor1^xor2;
    }
};

