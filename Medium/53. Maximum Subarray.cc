class Solution {
public:

    int max(int a, int b) {
        if (a >= b) return a;
        return b;
    }

    int maxSubArray(vector<int>& nums) {
        int maxsofar = nums[0];
        int maxendhere = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxendhere = max(maxendhere + nums[i], nums[i]);
            maxsofar = max(maxsofar, maxendhere);
        }
        return maxsofar;
    }
};

/*
Let's think about why this works. For any i, we have two cases:

Case 1: i is nonnegative.

Case 2: i is negative. 

STUDY THIS MORE IN-DEPTH
*/