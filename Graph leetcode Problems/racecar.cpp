// Race car leetcode 818

// Finding the shortest sequence of acceleration/reverse command to reach 
//          a target position on the track

class Solution {
public:
    int racecar(int target) {
      // 0 position, +1 velocity
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            int moves = item[0];
            int position = item[1];
            int velocity = item[2];
            
            if (position == target) {
                return moves;
            }
            
            if (abs(position) > 2 * target) {     // Here it stops whenever we passes twice the vector of the target
                continue;
            }
            q.push({moves + 1, position + velocity, 2 * velocity});
            
            if ((position + velocity > target && velocity > 0) ||
               (position + velocity < target && velocity < 0)) {
                q.push({moves + 1, position, (velocity > 0) ? -1 : 1});
            }
        }
        
        return 0;
    }
};