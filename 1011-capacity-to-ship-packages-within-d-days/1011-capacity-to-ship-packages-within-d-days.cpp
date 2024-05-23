class Solution {
public:

    int getdays(vector<int>weights,int cap){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]<=cap){
                load+=weights[i];
            }
            else{
                day++;
                load=weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        /*
        int n=weights.size();
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        for(int i=maxi;i<=sum;i++){
            int d=getdays(weights,i);
            if(d<=days){
                return i;
            }
        }
        return -1;
        */

        int maxi=INT_MIN;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(maxi<weights[i]){
                maxi=weights[i];
            }
            sum+=weights[i];
        }
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int d=getdays(weights,mid);
            if(d>days){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};