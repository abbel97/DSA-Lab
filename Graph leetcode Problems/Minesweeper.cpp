// Minesweeper Leetcode 

// From given board on a click, we reveal squares as Minesweeper rules
//          which is expanding blank regions or hit mine.

class Solution {
    public:
        vector<int>dirX={-1,0,1,-1,1,-1,0,1};
        vector<int>dirY={-1,-1,-1,0,0,1,1,1};
        void depthFirstSearch(int row,int col,int rows,int cols,vector<vector<int>>& visited,vector<vector<char>>& board)
        {
            visited[row][col]=1;
            if(board[row][col]=='M'){
                board[row][col]='X';
                return;
            }
            int mineCount=0;
            for(int i=0;i<8;i++){
                int newRow = row + dirX[i], newCol = col + dirY[i];
                if(newRow >= 0 && newCol >= 0 && newRow < rows &&newCol < cols){
                    if(board[newRow][newCol]=='M') mineCount++;
                }
            }
            if(mineCount!=0) board[row][col]='0' + mineCount;
            else{
                board[row][col]='B';
                for(int i=0;i<8;i++){
                    int newRow = row + dirX[i], newCol = col+dirY[i];
                    if(newRow >= 0 && newCol >= 0 && newRow < rows &&newCol < cols){
                       if(board[newRow][newCol]=='E' && !visited[newRow][newCol]) depthFirstSearch(newRow,newCol,rows,cols,visited,board);
                    }
                }
            }
            return;
        }
        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            int rows = board.size(),cols=board[0].size();
            vector<vector<int>>visited(rows,vector<int>(cols,0));
            depthFirstSearch(click[0],click[1],rows,cols,visited,board);
            return board;
        }
    };