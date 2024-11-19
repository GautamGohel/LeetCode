class Solution {
public:

    int findmax(vector<vector<int>>arr,int mid,int n,int m){
        int maxi=-1;
        int ind=n;
        for(int i=0;i<n;i++){
            if(arr[i][mid]>maxi){
                maxi=arr[i][mid];
                ind=i;
            }
        }
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int n=mat.size();
         int m=mat[0].size();
         int l=0,h=m-1;
         while(l<=h){
            int mid=(l+h)/2;
            int row=findmax(mat,mid,n,m);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left and mat[row][mid]>right){
                return {row,mid};
            }else if(mat[row][mid]<left){
                h=mid-1;
            }else{
                l=mid+1;
            }
         }
         return {-1,-1};
    }
};