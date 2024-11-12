class Solution {
    private:
        
      int ispossible(vector<int>bloomDay,int mid,int m,int k){
        int n=bloomDay.size();
        int cnt=0;
        int x=0;
         for(int i=0;i<n;i++){
             if(bloomDay[i]<=mid){
                x++;
                if(x==k){
                    cnt++;
                    x=0;
                }
             }else{
                x=0;
             }
         }
         return cnt>=m;
      }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int n=bloomDay.size();
        long long val=m*1ll*k;
        if(n<val){
            return -1;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(ispossible(bloomDay,mid,m,k)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};