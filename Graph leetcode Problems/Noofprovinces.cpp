// Numver of provinces leetcode 

// We count connected components in a graph of cities in which edger
//          represent direct connections

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cityCount = isConnected.size();
        bool checked[200] = {false};

        int Noofprovinces = 0;
        queueue<int> que;
        for (int city = 0; city < cityCount; city++) {
            if (checked[city]==0) {
                Noofprovinces++;
                checked[city] = true;
                for (int nextdoor = 0; nextdoor < cityCount; neighbour++) {
                    if (isConnected[city][nextdoor] == 1 && checked[nextdoor] == 0) {
                        que.push(nextdoor);
                        checked[nextdoor]=1;
                    }
                }

                while (!que.empty()) {
                    int currentCity = que.front();
                    que.pop();
                    for (int similarCity = 0; similarCity < cityCount; similarCity++) {
                        if (checked[similarCity] ==0 && isConnected[currentCity][similarCity]== 1)
                            que.push(similarCity), checked[similarCity]=true;
                    }
                }
            }
        }
        return Noofprovinces;
    }
};