class Solution {
public:
    
    bool issafe(int row,int col,vector<string>board,int n){
        int oldrow=row;
        int oldcol=col;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=oldrow;
        col=oldcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=oldrow;
        col=oldcol;
        while(row<n and col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(i,col,board,n)){
                board[i][col]='Q';
                solve(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
    }
   
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>boards(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            boards[i]=s;
        }
        solve(0,boards,ans,n);
        return ans;
    }
};