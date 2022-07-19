class Solution {
public:
    

    #if 0
    vector<vector<int>> power_set;

    void resetBitset(vector<bool> bs) {
        for (int i = 0; i < bs.size(); ++i) {
            bs[i] = false;
        }
    }

    // all elements are unique - use this to your advantage
    vector<vector<int>> subsets(vector<int>& nums) {
        // power set should be the union of all subsets of size 0, 
        //   of size 1, of size 2, etc.

        // original method: treat this problem as n different problems
        //      of (get all subsets of size k of a set of size n).
        //      Use the algorithm for generating combinations of numbers
        //      from problem 77.
        
        // second method: instead of this, start with the empty vector.
        //      add nums[0] to one copy, nums[1] to another copy, and so on.
        //      Pass each of these vectors into a recursive call which makes
        //      n - k copies of the given vector such that each of the 
        //      n - k remaining elements (where k is the last element in the
        //      given vector) is added. Continue this until
        //      you've reached the last element possible.

        // third method: recall from math 239 that the power set of any 
        //      set of size n is bijective with the set of binary strings
        //      of length n. Simply generate all binary strings of length 
        //      n, and map each one to a different subset.
        
        vector<bool> bs;
        bs.resize(nums.size());
    
        int k = 0;
        int j = 0;
        while (true) {
            
            vector<int> subset;

            mapping:
            subset.clear();
            for (int i = 0; i < nums.size(); ++i) {
                if (bs[i] == true) {
                    subset.push_back(nums[i]);
                }
            }
            power_set.push_back(subset);
            if (!bs[k]) {
                bs[k] = true;
                goto mapping;
            }

            k++;

            if (j <= k) {
                j++;
                if (j == nums.size()) {
                    break;
                }
                resetBitset(bs);
                bs[j] = true;
                k = 0;
            }
            // fundamentally broken way of iterating through all binary strings
            // but yes, this is the idea
        }
        return power_set;
        // ways to optimize:
        //   use the same vector instead of creating a new one every iteration
        //   (there are only a few changes you make each time)
        
    }
    #endif
};