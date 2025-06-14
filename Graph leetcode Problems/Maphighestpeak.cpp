// Map of highest peak leetcode 1765

//We'll assign heights to cell so the water spreads outward 
//      and maximizing the minimum height difference

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
        queue<pair<int,int>>q;
        int a = water.size();
        int b = water[0].size();
        for(int i = 0;i < a; i++){
            for(int j = 0; j < b; j++){
                if(water[i][j]==1){
                    water[i][j] = 0;
                    q.push({i,j});
                }
                else {
                    water[i][j] = -1;
                }
            }
        }
        int ab[5] = {0,1,0,-1,0};
        while(q.size()){
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;
            for(int i = 0;i < 4; i++){
                int ax = x + ab[i];
                int ay = y + ab[i+1];
                if(ax > -1 && ax < a && ay > -1 && ay < b && water[ax][ay] == -1){
                    water[ax][ay] = 1 + water[x][y];
                    q.push(
                        {ax,ay});
                }
            }
        }
        return water;
    }
};