class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        /*
        int n=arr.size();
        for (int i = 0; i < n; i++) {
        if (arr[i] <= k) k++; 
        else break;
    }
    return k;
    }
    */
     int n=arr.size();
     int low=0;
     int high=n-1;
     while(low<=high){
        int mid=(low+high)/2;
        int miss=arr[mid]-mid-1;
        if(miss<k){
          low=mid+1;
        }
        else{
            high=mid-1;
        }
     }
     return high+k+1;
    }
};