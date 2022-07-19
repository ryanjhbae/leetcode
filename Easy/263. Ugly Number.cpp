class Solution {
public:
    
    bool isUgly(int n) {
        int quotient;
        if (n <= 0) return false;
        while (abs(n) > 1) {
            quotient = n / 2;
            if (2 * quotient != n) {
                quotient = n / 3;
                if (3 * quotient != n) {
                    quotient = n / 5;
                    
                    if (5 * quotient != n) {
                        return false;
                    }
                }
            }
            n = quotient;
        }
        return true;
    }
};