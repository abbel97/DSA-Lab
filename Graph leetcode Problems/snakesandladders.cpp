//Snakes and Ladders leetcode 909

// We'll model the classic boared game as a graph and then we compute the minimum die
//   rolls to reach the last square qccounting for snakes and ladders using BFS search

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int num = board.size();
        set<int> visited;
        auto getPos = [&](int pos) {
            int row = (pos - 1) / num;
            int colums = (pos - 1) % num;
            if (row % 2 == 1) colums = num - 1 - colums;
            row = num - 1 - row;
            return make_pair(row, colums);
        };
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();

            for (int i = 1; i < 7; ++i) {
                int newPos = i + pos;
                auto [r, c] = getPos(newPos);

                if (board[r][c] != -1) newPos = board[r][c];
                if (newPos == num * num) return moves + 1;

                if (!visited.count(newPos)) {
                    visited.insert(newPos);
                    q.push({newPos, moves + 1});
                }
            }
        }
        return -1;
    }
};