class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int free_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[free_idx] = nums[i];
                free_idx += 1;
            }
        }
        return free_idx;
    }
};