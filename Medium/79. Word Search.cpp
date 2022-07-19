class Solution {
public:
    
    // originally, i used an unordered_map, but it exceeded the time limit.
    //   i switched to "marking" visited tiles instead
    //   (this idea came from looking at the discussion section, but the 
    //   rest of the algorithm is mine)
    
    const char VISITED = 0;
    #define prev 0
    #if prev
    std::unordered_map<int, std::unordered_set<int>> visited;
    #endif
    
    bool inBounds(vector<vector<char>> &board, int i, int j) {
        return (0 <= i && i < board.size()) && (0 <= j && j < board[0].size());
    }
    
    // determines if word[idx...end] exists on board, starting the search at 
    // board[i][j]
    bool existRecursive(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        
        if (!inBounds(board, i, j)) {
            return false;
        }
        #if prev
        auto lookupResult = visited.find(i);
        if (lookupResult != visited.end()) {
            if (lookupResult->second.find(j) != lookupResult->second.end()) {
                return false;
            }
        }
        #endif
        
        if (idx == word.length() - 1) {
            return board[i][j] == word[idx];
        } else if (word[idx] != board[i][j]) {
            return false;
        } else {
            #if prev
            if (lookupResult == visited.end()) {
                visited.emplace(i, std::unordered_set<int>({j}));
            } else {
                lookupResult->second.insert(j);
            }
            #endif
            char c = board[i][j];
            board[i][j] = VISITED;
            
            bool ret =  existRecursive(board, word, i - 1, j, idx + 1) || // up
                        existRecursive(board, word, i, j + 1, idx + 1) || // right
                        existRecursive(board, word, i + 1, j, idx + 1) || // down
                        existRecursive(board, word, i, j - 1, idx + 1); // left
            #if prev
            visited.find(i)->second.erase(j);
            #endif
            board[i][j] = c;
            
            return ret;
        }   
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && existRecursive(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
};