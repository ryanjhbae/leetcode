class Solution {
public:
    
    //ugly solution but intuitive and decently fast

    // you don't actually need two queues
    const int EMPTY = 0;
    const int FRESH = 1;
    const int ROTTEN = 2;
    const int IMPOSSIBLE = -1;
    
    bool inBounds(vector<vector<int>> &grid, int i, int j) {
        return (0 <= i && i < grid.size()) && (0 <= j && j < grid[0].size());
    }
    
    bool isEmpty(int n) {
        return n == EMPTY;
    }
    
    bool isRotten(int n) {
        return n == ROTTEN;
    }
    
    bool isFresh(int n) {
        return n == FRESH;
    }
    
    void emplaceIfInBounds(queue<pair<int, int>> *q, int i, int j, vector<vector<int>> &grid) {
        if (inBounds(grid, i, j)) {
            q->emplace(i, j);
        }
    }
    
    // smells like dfs/bfs
    // min number of minutes that must elapse until no cell has a fresh orange
    //   = the largest distance between a fresh orange and the nearest rotten
    //   orange
    // draw out some examples and see
    int orangesRotting(vector<vector<int>>& grid) {
        // initial approach: actually simulate the "minutes"
        // O(m * n * k) time, where k is the number of minutes we return
        
        // the cells for the current minute
        queue<pair<int, int>> *currentQueue = new queue<pair<int, int>>;
        
        // the cells of the next minute
        queue<pair<int, int>> *nextQueue = new queue<pair<int, int>>;
        
        int freshCount = 0;
        
        // add all initially rotten oranges
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (isRotten(grid[i][j])) {
                    emplaceIfInBounds(nextQueue, i - 1, j, grid);
                    emplaceIfInBounds(nextQueue, i, j + 1, grid);
                    emplaceIfInBounds(nextQueue, i + 1, j, grid);
                    emplaceIfInBounds(nextQueue, i, j - 1, grid);
                } else if (isFresh(grid[i][j])) {
                    freshCount++;
                }
            }
        }
        if (freshCount == 0) return 0;
        
        queue<pair<int, int>> *tempQueue;
        int minutes = -1; 
        while (!nextQueue->empty()) {
            tempQueue = currentQueue;
            currentQueue = nextQueue;
            nextQueue = tempQueue;
            while (!currentQueue->empty()) {
                int i = currentQueue->front().first;
                int j = currentQueue->front().second;
                currentQueue->pop();
                if (!isFresh(grid[i][j])) {
                    continue;
                }
                freshCount--;
                grid[i][j] = ROTTEN;
                emplaceIfInBounds(nextQueue, i - 1, j, grid);
                emplaceIfInBounds(nextQueue, i, j + 1, grid);
                emplaceIfInBounds(nextQueue, i + 1, j, grid);
                emplaceIfInBounds(nextQueue, i, j - 1, grid);
            }
            
            minutes += 1;
        }
        
        delete currentQueue;
        delete nextQueue;
        
        if (freshCount != 0) {
            return IMPOSSIBLE;
        }
        return minutes;
    }
};