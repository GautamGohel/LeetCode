class Solution {
public:

      bool ispossible(int col,int row,vector<string>&board,int n){
        int tempcol=col,temprow=row;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
            row--;
        }
        col=tempcol;
        row=temprow;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col=tempcol;
        row=temprow;
        while(col>=0 and row<n){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
            row++;
        }
        return true;
}

    void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(ispossible(col,row,board,n)){
              board[row][col]='Q';
              solve(col+1,n,board,ans);
              board[row][col]='.';
            }
        }
    }
  
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(0,n,board,ans);
        return ans;
    }
};