class Solution {
public:
    
    int min(int a, int b) {
        if (a <= b) return a;
        else return b;
    }

    // return true iff there are two distinct indices i and j in the array
    //   such that they are equal and the distance between is k or less
    
    // should be O(n)
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map integers to indices
        std::unordered_map<int, int> map;
        int j = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end()) {
                return true;
            } 
            map[nums[i]] = i;
            /*
            if (map.find(nums[j]) != map.end()) {
                return true;
            }
            map[nums[j]] = j;
            */
            if (i >= k) {
                map.erase(nums[i - k]);
            }
        }
        return false;
    }
    
    
    // monke solution O(kn)
    #if 0
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < min(nums.size(), i + k + 1); ++j) {
                if (nums[j] == nums[i]) return true;
            }
        }
        return false;
    }
    #endif
};