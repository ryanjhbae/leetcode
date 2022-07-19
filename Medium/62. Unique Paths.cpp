class Solution {
public:
    int uniquePaths(int m, int n) {
        // hint: dynamic programming
        // BRC: bottom right corner
        // really, this is (number of ways to get to tile left of BRC)
        //               + (number of ways to get to tile above BRC)
        // since for each of these you can just go right/down to get to the BRC
        // m = 1, n = 1, => 0
        // m = 2, n = 1, => 1
        // m = 1, n = 2 => 1
        // m = 2, n = 2, => 2
        
        // so really it's uniquePaths(m - 1, n) + uniquePaths(m, n - 1)
        
        // initial approach: time-space tradeoff
        //   use a 2d array of size mxn to record uniquePaths(i, j) for each i, j <= m, n
        //   uniquePaths(i, j) is stored in uniquePathsArray[i - 1][j - 1]
        
        int uniquePathsArray[m][n];
        
        for (int j = 0; j < n; ++j) {
            
            for (int i = 0; i < m; ++i) {
                if (i == 0 && j == 0) {
                    uniquePathsArray[i][j] = 1;
                } else if (i == 0 || j == 0) {
                    uniquePathsArray[i][j] = 1;
                } else {
                    uniquePathsArray[i][j] = uniquePathsArray[i - 1][j] + uniquePathsArray[i][j - 1];
                }   
            }
        }
        return uniquePathsArray[m - 1][n - 1];
    }
};