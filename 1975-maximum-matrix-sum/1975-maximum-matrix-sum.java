class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int cnt=0;
        long sum=0;
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<matrix.length;i++){
          for(int j=0;j<matrix[0].length;j++){
            if(matrix[i][j]<0){
                cnt++;
            }
            mini=Math.min(mini,Math.abs(matrix[i][j]));
            sum+=Math.abs(matrix[i][j]);
          }
        }
        if((cnt&1)==1){
            return sum-2*mini;
        }
        return sum;
    }
}