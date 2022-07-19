// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // O(logn) solution
        // if !isBadVersion(i), then we need to search later 
        
        int lo = 1;
        int hi = n;
        int mid = lo + (hi - lo) / 2;
        while (lo < hi) {
            
            if (isBadVersion(mid)) {
                if (!isBadVersion(mid - 1)) {
                    return mid;
                } else {
                    hi = mid - 1;
                }
            } else {
                lo = mid + 1;
            }
            mid = lo + (hi - lo) / 2;
        }
        return mid;
        
        #if 0
        // O(n) solution (exceeds time limit)
        for (int i = 1; i <= n; ++i) {
            if (isBadVersion(i)) {
                return i;
            }
        }
        return n;
        #endif
    }
};