class Solution {
public:
    
    bool inBounds(string &s, int i, int j) {
        return (0 <= i && i < s.length()) && (0 <= j && j < s.length());
    }
    
    // O(n) palindrome check
    bool isAPalindrome(string &s, int i, int j, vector<vector<int>> &palindromeMap) {
        if (!inBounds(s, i, j) || i > j) {
            return false;
        } else if (palindromeMap[i][j] != -1) {
            return palindromeMap[i][j];
        } 
        
        bool result = false;
        
        if (i == j || ((j == i + 1) && s[i] == s[j])) {
            result = true;
        } else if (isAPalindrome(s, i + 1, j - 1, palindromeMap)) {
            result = (s[i] == s[j]);
        }
        
        palindromeMap[i][j] = result;
        return result;
    }
    
    // dynamic programming using tabulation
    string longestPalindrome(string s) {
        vector<vector<int>> palindromeMap;
        int start = 0;
        int len = 1;
        
        palindromeMap.resize(s.length());
        for (int i = 0; i < s.length(); ++i) {
            palindromeMap[i].resize(s.length(), -1);
        }
        for (int i = 0; i < s.length(); ++i) {
            
            for (int j = 0; j < s.length() - i; ++j) {
                
                // cleverly structure the loop so we go through
                // the shortest lengths first
                if (isAPalindrome(s, j, j + i, palindromeMap) && i + 1 > len) {
                    start = j;
                    len = i + 1;
                }
            }
        }
        return s.substr(start, len);
    }
};