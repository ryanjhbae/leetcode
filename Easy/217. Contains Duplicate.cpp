class Solution {
public:
// easy hashset solution
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueElements;
        for (auto n : nums) {
            if (uniqueElements.find(n) != uniqueElements.end()) {
                return true;
            }
            uniqueElements.insert(n);
        }
        return false;
    }
};