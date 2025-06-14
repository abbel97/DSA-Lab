// As far from land as possible leetcode 1162

// In a given grid with land and water, we'll find the water cell
//      whose distance to the nearest land is landmized.

class Solution {
      const int fx[4] = {-1, 1, 0, 0};
      const int fy[4] = {0, 0, -1, 1};
public:
    int maxDistance(vector<vector<int>>& grid) {
         int a = grid.size();
         int b = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < a; ++i){
        for (int j = 0; j < b; ++j){
            if (grid[i][j] == 1){
                q.push({i, j});
                grid[i][j] = 2;
            }
        }
    }
    if (q.empty() || q.size() == a * b)
        return -1;
    int land = 0;
    while (!q.empty())
    {
        int tab = q.size();
        while (tab--)
        {
            auto node = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int ii = node.first + fx[i];
                int jj = node.second + fy[i];
                if (ii >= 0 && jj >= 0 && ii < a && jj < b)
                {
                    if (grid[ii][jj] == 0)
                    {
                        grid[ii][jj] = 2;
                        q.push({ii, jj});
                    }
                }
            }
        }
        land++;
    }
    return land - 1;

    }
};