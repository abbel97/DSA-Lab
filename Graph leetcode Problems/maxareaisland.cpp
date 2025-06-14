// Max Area of Island leetcode 695

// We compute the largest connected region of 1's(land) in 2D grid.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int land = 0;
        a = grid.size(), b = grid[0].size();
        for (int i = 0; i < a; i++) 
            for (int j =0; j < b; j++)
                if (grid[i][j]) land = max(land, area(i, j, grid));
        return land;
    }
private:
    int a, b;
    int area(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= a || j >= b || !grid[i][j]) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + area(i-1, j, grid) + area(i, j-1, grid) + 
        area(i+1, j, grid) + area(i, j+1, grid);
    }
};

