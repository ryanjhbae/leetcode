class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int unique_count = 1;
        int next_idx = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != prev) {
                unique_count += 1;
                prev = nums[i];
                nums[next_idx] = nums[i];
                next_idx += 1;
            }
        }
        return unique_count;
    }
};