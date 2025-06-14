// Open the lock leetcode 752

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }
        queue<int> queue;
        queue.push(0);
        bool is[10000]{false};
        for (auto& d : deadends)
            is[stoi(d)] = true;
        int targ = stoi(target);
        if (is[0]) {
            return -1;
            }
        for (int turns = 1; queue.size(); turns++) {
            int qlen = queue.size();
            for (int i = 0; i < qlen; i++) {
                int curr = queue.front();
                queue.pop();
                for (int j = 1; j < 10000; j *= 10) {
                    int mask = curr % (j * 10) / j,
                        masked = curr - (mask * j);
                    for (int k = 1; k < 10; k += 8) {
                        int ab = masked + (mask + k) % 10 * j;
                        if (is[ab]) {
                            continue;
                        }
                        if (ab == targ) {
                            return turns;
                        }
                        is[ab] = true;
                        queue.push(ab);
                    }
                }
         }
         } 
         return -1;

    }
};