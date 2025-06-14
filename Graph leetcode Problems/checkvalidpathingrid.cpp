// Check if there is a valid path in a grid leetcode 1391

// Each cells have one of six street shapes, we determine if there is a path from the 
//              top left to the bottom right

class Solution {
    public:
        bool hasValidPath(vector<vector<int>>& grid) {
            int rows = grid.size() , cols = grid[0].size() ;
            array<array<int , 2>, 4> directions;
            directions[0] = {-1 , 0};
            directions[1] = {0, 1};
            directions[2] = {1 , 0};
            directions[3] = {0 , -1};
        array<array<int, 2> , 7> streetShapes ;
            streetShapes[1] = { 3 , 1 } ; streetShapes[2] = { 0 , 2 } ;
            streetShapes[3] = { 3 , 2 } ;
            streetShapes[4] = { 1 , 2 } ;
            streetShapes[5] = { 0 , 3 } ;
            streetShapes[6] = { 0 , 1 } ;
             array<int, 4> cells;
            cells[0] = 2 ;
            cells[1] = 3 ;
            cells[2] = 0 ;
            cells[3] = 1 ;
            
    
            queue<array<int ,2>> que ;
            que.push({0,0}) ;
            grid[0][0] += 6 ;
            while(!que.empty()){
                auto [currentRow,currentCol] = que.front() ; 
                que.pop() ;
                if(currentRow == rows-1 and currentCol == cols-1 ) return true ;
                
                for(auto &dir : streetShapes[grid[currentRow][currentCol]-6]) {
                    int addRow = directions[dir][0] + currentRow ;
                    int addCol = directions[dir][1] + currentCol ;
                    
                    if(addRow < 0 || addCol < 0 || addRow >= rows 
                        || addCol >= cols || grid[addRow][addCol] > 6  ) {
                            continue;
                        }
                    
                    for( auto &connectdir : streetShapes[grid[addRow][addCol]]){
                        if(cells[dir] == connectdir) { 
                            que.push({addRow,addCol}) ; 
                            grid[addRow][addCol] += 6 ;
                            break ;
                        }
                    }
                }
                
            }
    
            return false ;
        }
    };