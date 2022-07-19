class Solution {
public:
    // easy hashmap solution
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> indexMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int needed_int = target - nums[i];
            auto lookupResult = indexMap.find(needed_int);
            if (lookupResult == indexMap.end()) {
                indexMap.emplace(nums[i], i);
            } else {
                res.push_back(i);
                res.push_back(lookupResult->second);
                break;
            }
        }
        return res;
    }
};