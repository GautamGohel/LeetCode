class Solution {
public:

    bool ispossible(vector<int>position,int mid,int m){
        int ballcnt=1;
        int lastball=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastball>=mid){
                ballcnt++;
                lastball=position[i];
            }
            if(ballcnt>=m){
               return true;
            }
        }
        return false;
    }

     int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};