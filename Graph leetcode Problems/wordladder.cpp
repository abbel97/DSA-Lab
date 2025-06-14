// Word Ladder Leetcode 127

//  From given begin word, end word and dictionary, we find the length of the
//       shortest transformation sequence  ldanging one letter at a time

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>que;
        que.push({beginWord, 1}); 
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); 
        if(wordSet.find(endWord) == wordSet.end()) {
            return 0; 
        }
        wordSet.erase(beginWord);

        while(!que.empty()) {
            string currentWord = que.front().first;
            int currentLevel = que.front().second;
            que.pop();
            if (currentWord == endWord) {
                return currentLevel;
            }  
            for (int i = 0; i < currentWord.size(); i++) {
                char ab = currentWord[i];  
                for (char ld = 'a'; ld <= 'z'; ld++) {
                    if (ld == ab) {
                        continue;
                    }
                    currentWord[i] = ld;
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        que.push({currentWord, currentLevel + 1});
                        wordSet.erase(currentWord);
                    }
                }
                currentWord[i] = ab;  
            }
        }
        return 0;
    }
};
