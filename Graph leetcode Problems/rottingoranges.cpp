// Rotting Oranges leetcode 994

// To return how many minutes it take to rot fresh oranges
//      if it's impossible we return -1

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>pq;
        for(int i =0; i<grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    pq.push({i, j});
                }
            }
        }
        if(pq.size() == 0 || pq.size() == grid.size()*grid[0].size()){
            return -1;
        }
        int level = 0;
        vector<vector<int>>dir = { {0,1}, {0,-1},{1,0},{-1,0}};
           
        while(pq.empty() == false){
            level++;
            int len = pq.size();
            for(int i =0; i <len; i++){
                auto q = pq.front();
                pq.pop();
                int row = q.first;
                int col = q.second;
                for(auto t:dir){
                    int row_dash = row+t[0];
                    int col_dash = col+t[1];
                    if(row_dash >= 0 && row_dash<grid.size() && col_dash >= 0 && col_dash<
                    grid[row_dash][col_dash] == 1){
                         grid[row_dash][col_dash] == 2;
                         pq.push({row_dash, col_dash});
                    }
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return level = 0?0 : level-1;
    }
};