class Solution {
public:
    int mySqrt(int x) {
        /*
        int ans=0;
        for(int i=0;i<=x;i++){
            if(i*i<=x){
               ans=i;
            }
            else{
                break;
            }
        }
        return ans;
        */
        long long low=1,high=x;

        while(low<=high){
            long long mid=(low+high)/2;
            long long val=mid*mid;
            if(val<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};