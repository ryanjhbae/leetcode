class Solution {
public:
    const int RIGHT = 0;
    const int DOWN = 1;
    const int LEFT = 2;
    const int UP = 3;
    
    // the algorithm seems pretty intuitive, though hard to put into code
    // O(m * n) complexity (only visit each cell once)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = 0;
        int col = 0;
        
        int min_col = 0;
        int min_row = 0;
        int max_col = matrix[0].size() - 1;
        int max_row = matrix.size() - 1;
        
        vector<int> result;
        result.push_back(matrix[0][0]);
        int d = RIGHT;
        
        while ((min_col <= col && col <= max_col) || (min_row <= row && row <= max_row)) {
            
            if (d == RIGHT) {
                for (int i = col + 1; i <= max_col; ++i) {
                    result.push_back(matrix[row][i]);
                }
                col = max_col;
                min_row++;
            } else if (d == LEFT) {
                for (int i = col - 1; i >= min_col; --i) {
                    result.push_back(matrix[row][i]);
                }
                col = min_col;
                max_row--;
            } else if (d == DOWN) {
                for (int i = row + 1; i <= max_row; ++i) {
                    result.push_back(matrix[i][col]);
                }
                row = max_row;
                max_col--;
            } else { // d == UP
                for (int i = row - 1; i >= min_row; --i) {
                    result.push_back(matrix[i][col]);
                }
                row = min_row;
                min_col++;
            }
            
            if (d == UP) {
                d = RIGHT;
            } else {
                d++;
            }
        }
        return result;
    }
};