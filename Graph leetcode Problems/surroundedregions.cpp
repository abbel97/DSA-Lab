// Surrounded regions Leetcode 130

// We flip all O's that aren't connected to the border 'X' in a 2D board

class Solution {
    private:
    void flip(vector<vector<char>>& abx_board, vector<vector<char>>& bps_curr, int i, int j, bool& on_border){
        if(i < 0 || j < 0 || i == abx_board.size() || 
        j == abx_board[0].size() || bps_curr[i][j] == 'X'){
            return;
        }
        if((i == 0 || j == 0 || i == abx_board.size() - 1 || 
        j == abx_board[0].size() - 1) && !on_border){
            on_border = true;
        }
        // we are doing using the copies of the board.
        bps_curr[i][j] = 'X';
        abx_board[i][j] = 'X';
        flip(abx_board, bps_curr, i - 1, j, on_border);
        flip(abx_board, bps_curr, i + 1, j, on_border);
        flip(abx_board, bps_curr, i, j - 1, on_border);
        flip(abx_board, bps_curr, i, j + 1, on_border);
    }

    public:
    void solve(vector<vector<char>>& board) {
        vector<vector<char>> abx_curr, bps_curr;
        abx_curr = bps_curr = board;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                bool on_border = false;
                if(bps_curr[i][j] == 'O'){
                    flip(abx_curr, bps_curr, i, j, on_border);
                    if(!on_border){board = abx_curr;}
                    else{abx_curr = board;}
                }
            }
        }
    }
};