class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        if(total-d<0 or (total-d)%2!=0){
            return 0;
        }
        int target=(total-d)/2;
        vector<int>prev(target+1,0);
        for(int i=0;i<=target;i++){
            if(i==0 and arr[0]==0) prev[i]=2;
            else if(arr[0]==i or i==0) prev[i]=1;
            else prev[i]==0;
        }
        for(int i=1;i<n;i++){
            vector<int>curr(target+1,0);
            for(int j=0;j<=target;j++){
                int pick=0;
                if(arr[i]<=j) pick=prev[j-arr[i]];
                int notpick=prev[j];
                curr[j]=pick+notpick;
            }
            prev=curr;
        }
        return prev[target];
    }
    int findTargetSumWays(vector<int>& arr, int tg) {
       return countPartitions(arr,tg);
    }
};