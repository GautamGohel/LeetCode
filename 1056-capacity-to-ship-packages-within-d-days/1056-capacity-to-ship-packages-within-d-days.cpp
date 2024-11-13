class Solution {

private:
    int cntans(vector<int>weights,int w){
        int day=1;
        int weight=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
           if(weight+weights[i]<=w){
            weight+=weights[i];
            }else{
                    day++;
                    weight=weights[i];
                }
        }
        return day;
    }


public:
    int shipWithinDays(vector<int>& weights, int days) {
       int n=weights.size();
       int l=*max_element(weights.begin(),weights.end());
       int total=accumulate(weights.begin(),weights.end(),0);
       int h=total;
       while(l<=h){
         int mid=l+(h-l)/2;
         if(cntans(weights,mid)<=days){
            h=mid-1;
         }else{
            l=mid+1;
         }
       }   
       return l;
    }
};