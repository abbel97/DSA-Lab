//Keys and Rooms leetcode 841

// The listed rooms contain keys to other rooms, we'll determine if we can visit each 
//          room starting from 0

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       set<int> visitedRooms;
       queue<int> q;

       q.push(0);
      
       while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            int currentRoom = q.front();
            q.pop();
            visitedRooms.insert(currentRoom);
            vector<int>keys = rooms[currentRoom];
            for(int j = 0; j < keys.size(); j++){
                if(visitedRooms.find(keys[j]) == visitedRooms.end()){
                    q.push(keys[j]);
                }
            }
        }
       }
       return visitedRooms.size() == rooms.size();
  }  
};
