class Solution {
    public int countNegatives(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        // int cnt=0;
        // for(int i=0;i<m;i++){
        //    int l=0,h=n-1;
        //    while(l<=h){
        //     int mid=(l+h)/2;
        //     if(grid[i][mid]<0){
        //         h=mid-1;
        //     }else{
        //         l=mid+1;
        //     }
        //    }
        //    if(l<n) cnt+=n-l;
        // }

        int r=m-1;
        int c=0;
        int cnt=0;
        while(r>=0 && c<n){
            if(grid[r][c]<0){
                cnt+=n-c;
                r--;
            }else{
                c++;
            }
        }
        return cnt;
    }
}