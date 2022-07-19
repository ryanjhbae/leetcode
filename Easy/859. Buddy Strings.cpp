class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        // determine if you can swap two letters in s so the result is goal
        // you can easily do this in Theta(n) time
        
        // assume true.
        // if you encounter any letter s[i] that doesn't match goal[i],
        //   there should be exactly one other letter s[j] that doesn't match goal[j]
        //   such that s[i] and s[j] should be in each other's places

        bool firstLetterFound = false;
        int firstLetterIndex;
        bool secondLetterFound = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != goal[i]) {
                if (firstLetterFound) {
                    // if there is a third mismatched letter
                    if (secondLetterFound) {
                        return false;
                    }
                    secondLetterFound = true;
                    // if not swappable with the first letter
                    if (goal[i] != s[firstLetterIndex] || s[i] != goal[firstLetterIndex]) {
                            return false;
                    }
                // if there is only one mismatched letter
                } else if (i == s.length() - 1) {
                    return false;
                } else {
                    firstLetterIndex = i;
                    firstLetterFound = true;
                }
            }
        }
        return firstLetterFound && secondLetterFound;
    }
};