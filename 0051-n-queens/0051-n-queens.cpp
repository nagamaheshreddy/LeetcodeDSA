class Solution {
public:
    unordered_set<int>cols;
    unordered_set<int>posDiag;
    unordered_set<int>negDiag;

    void dfs(int row,int n,vector<string>&board,vector<vector<string>>&ans){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(cols.contains(col) || posDiag.contains(row+col) || negDiag.contains(row-col)){
                continue;
            }
            cols.insert(col);
            posDiag.insert(row+col);
            negDiag.insert(row-col);
            board[row][col]='Q';

            dfs(row+1,n,board,ans);

            cols.erase(col);
            posDiag.erase(row+col);
            negDiag.erase(row-col);
            board[row][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string str="";

        for(int i=0;i<n;i++){
            str+=".";
        }
        vector<string>board(n,str);
        


        dfs(0,n,board,ans);
        return ans;
    }
};