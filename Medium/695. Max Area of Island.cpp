class Solution {
public:
    
    int inBounds(vector<vector<int>> &grid, int i, int j) {
        return (0 <= i && i < grid.size()) && (0 <= j && j < grid[0].size());
    }
    
    int eraseIsland(vector<vector<int>> &grid, int i, int j) {
        std::stack<std::pair<int, int>> toVisit;
        toVisit.emplace(i, j);
        int area = 0;
        while (!toVisit.empty()) {
            int i = toVisit.top().first;
            int j = toVisit.top().second;
            toVisit.pop();
            if (!inBounds(grid, i, j) || !grid[i][j]) {
                continue;
            }
            area++;
            grid[i][j] = 0;
            toVisit.emplace(i, j - 1);
            toVisit.emplace(i + 1, j);
            toVisit.emplace(i, j + 1);
            toVisit.emplace(i - 1, j);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // this is easy af
        
        int maxArea = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    maxArea = std::max(maxArea, eraseIsland(grid, i, j));
                    
                }
            }
        }
        return maxArea;
    }
};