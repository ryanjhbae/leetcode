class Solution {
public:
// O(n) time
    double findMaxAverage(vector<int>& nums, int k) {
        // since we're always looking at subarrays of length k,
        //   just find the max subarray of length k and compute
        //   the avg by dividing it by k
        double runningSum = 0;
        for (int i = 0; i < k; ++i) {
            runningSum += nums[i];
        }
        
        double maxSumSoFar = runningSum;
        
        for (int i = k; i < nums.size(); ++i) {
            runningSum -= nums[i - k];
            runningSum += nums[i];
            if (runningSum > maxSumSoFar) {
                maxSumSoFar = runningSum;
            }
        }
        return maxSumSoFar / k;
    }
};