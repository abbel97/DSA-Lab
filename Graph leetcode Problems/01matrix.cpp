// 01 matrix leetcode 

// For each cell in biary matrix we compute its distance to the nearest 0-cell
//              we use 4-direcional moves

class Solution {
    public:
    // DFS may lead to stack efficiency and overflow
         vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
            int rows = grid.size(), cols=grid[0].size();
            vector<vector<bool>> seen(rows, vector<bool> (cols, false));
    
            queue<pair<int, pair<int, int>>> q;
            // {dist, {row, col}}
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(grid[i][j]==0){
                        q.push({0, {i, j}});
                        seen[i][j]=1;
                    } else seen[i][j]=0;
                }
            }
    
            int dx[]={1,0,-1,0};
            int dy[]={0,-1,0,1};
    
            while(!q.empty()){
                auto time = q.front(); q.pop();
                
                int distance=time.first;
                int row=time.second.first;
                int col=time.second.second;
    
                for(int i=0; i<4; i++){
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !seen[newRow][newCol]) {
                        q.push({distance+1, {newRow, newCol}});
                        seen[newRow][newCol]=1;
                        grid[newRow][newCol]=distance+1;
                    }
                }
            }
            return grid;
        }
    };