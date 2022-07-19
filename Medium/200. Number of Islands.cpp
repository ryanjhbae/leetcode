class Solution {
public:
    
    bool inBounds(vector<vector<char>> &grid, int i, int j) {
        return (0 <= i && i < grid.size()) && (0 <= j && j < grid[0].size());
    }
    
    // beginning at grid[i][j], "fills in" all connected land tiles to 
    //   mark them as visited
    // use dfs
    void mapOutIsland(vector<vector<char>>& grid, int i, int j) {
        if (!inBounds(grid, i, j)) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = '*';
        
        // right (makes sense to check right first since we begin in the top
        //   left corner and make our way to the right and down)
        mapOutIsland(grid, i + 1, j);
        // down
        mapOutIsland(grid, i, j + 1);
        // left
        mapOutIsland(grid, i - 1, j);
        // up
        mapOutIsland(grid, i, j - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    mapOutIsland(grid, i, j);
                    ++count;
                }
            }
        }
        
        return count;
    }
};