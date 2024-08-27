class Solution {

private:

    int solve(vector<int>& weights, int w){
       int sum=0;
       int n=weights.size();
       int day=1;
       for(int i=0;i<n;i++){
          if(sum+weights[i]<=w){
            sum+=weights[i];
          }else{
              sum=weights[i];
              day++;
          }
       }
       return day;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int total=0,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,weights[i]);
            total+=weights[i];
        }
        int l=maxi,h=total;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(weights,mid)<=days){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};