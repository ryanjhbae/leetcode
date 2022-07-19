class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        // Initial approach:
        
        // Sort the array, then pair the largest with the second
        //   largest, the third largest with the fourth largest,
        //   and so on
        
        // So the sum to return is just the sum of every other 
        //   element starting with the second-last (after sorting)
        
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = nums.size() - 2; i >= 0; i -= 2) {
            sum += nums[i];
        }
        
        return sum;
        
        // Better approach:
        
        // 
    }
};