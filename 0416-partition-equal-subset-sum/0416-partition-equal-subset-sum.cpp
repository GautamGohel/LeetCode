class Solution {
public:
   
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<bool>prev(target+1,false);
        if(arr[0]<=target){
           prev[arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            vector<bool>curr(target+1,false);
            curr[0]=true;
            for(int j=0;j<=target;j++){
                bool pick=false;
                if(arr[i]<=j){
                    pick=prev[j-arr[i]];
                }
                bool notpick=prev[j];
                curr[j]=pick or notpick;
            }
            prev=curr;
        }
        return prev[target];
    }
};