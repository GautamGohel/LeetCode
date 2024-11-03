class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(1){
            if(arr[l]+arr[h]==target){
                return {l,h};
            }
            else if(arr[l]+arr[h]<target){
                l++;
            }
            else{
                h--;
            }
        }
        return {-1,-1};
    }
};