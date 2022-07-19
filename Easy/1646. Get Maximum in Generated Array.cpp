class Solution {
public:
    
    int getMaximumGenerated(int n) {
        int max = 0;
        int nums[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            if (i == 0) {
                nums[i] = 0;
            } else if (i == 1) {
                nums[i] = 1;
            } else if (i % 2 == 0) {
                nums[i] = nums[i / 2];
            } else {
                int j = (i - 1) / 2;
                nums[i] = nums[j] + nums[j + 1];
            }
            if (nums[i] > max) { 
                max = nums[i]; 
            }
        }
        return max;
    }
};