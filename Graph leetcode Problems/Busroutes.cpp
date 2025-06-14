// Bus Routes Leetcode 815

// Given Bus lines, we find the minimum number of buses that we must take 
//          to travel from stop to destination.

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        unordered_map<int, vector<int>> adj; //key = stops, value = (indices)

        for(int route = 0; route < routes.size(); route++){
            for(auto &stop : routes[route]){
                adj[stop].push_back(route);
            }
        }
        queue<int> que;
        vector<bool> visited(501, false);
        for(auto &route :adj[source]){
            que.push(route);
            visited[route] = true;
        }
        int busCount = 1; //Source of the bus
        while(!que.empty()){
            int size = que.size();

            while(size--){
                int route = que.front();
                que.pop();

                for(auto &stop : routes[route]){
                        if(stop == target){
                            return busCount;
                        }
                        for(auto &nextRoute : adj[stop]){
                            if(visited[nextRoute] == false){
                                visited[nextRoute] = true;
                                que.push(nextRoute);
                            }
                        }
                }
            }
            busCount++;

        }
        return -1;
    }
};

