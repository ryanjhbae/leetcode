class Solution {
public:
    // O(n) (not optimal in practice)
    // the elements of nums are NOT necessarily unique
    int longestConsecutive(vector<int>& nums) {
        // maintain a mapping of integers to start and end elements
        // of sequences they are part of
        std::unordered_map<int, std::pair<int, int>> sequenceMap;
        
        int longest_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto lookupResult = sequenceMap.find(nums[i]);
            if (lookupResult != sequenceMap.end()) {
                // if the element is already in the map, we have 
                //   already considered it as part of a sequence
                continue;
            }
            
            // otherwise, search for nums[i] + 1 and nums[i] - 1
            auto lookupAboveResult = sequenceMap.find(nums[i] + 1);
            auto lookupBelowResult = sequenceMap.find(nums[i] - 1);
            
            // since we are only considering sequences made of unique
            // elements, our task is much simpler
            // we only need to worry about updating the start and end
            
            int start = nums[i];
            int end = nums[i];
            
            if (lookupAboveResult == sequenceMap.end() &&
                lookupBelowResult == sequenceMap.end()) {
                
                sequenceMap.emplace(nums[i], std::make_pair(nums[i], nums[i]));
                
            } else if (lookupAboveResult == sequenceMap.end() && 
                       lookupBelowResult != sequenceMap.end()) {
                
                // nums[i] is the new end of the sequence
                sequenceMap[lookupBelowResult->second.first].second = nums[i];
                sequenceMap.emplace(nums[i], std::make_pair(lookupBelowResult->second.first, nums[i]));
                start = lookupBelowResult->second.first;
                
            } else if (lookupAboveResult != sequenceMap.end() && 
                       lookupBelowResult == sequenceMap.end()) {
                
                // nums[i] is the new start of the sequence
                sequenceMap[lookupAboveResult->second.second].first = nums[i];
                sequenceMap.emplace(nums[i], std::make_pair(nums[i], lookupAboveResult->second.second));
                end = lookupAboveResult->second.second;
                
            } else {
                // join the two sequences
                sequenceMap[lookupBelowResult->second.first].second = lookupAboveResult->second.second;
                sequenceMap[lookupAboveResult->second.second].first = lookupBelowResult->second.first;
                sequenceMap.emplace(nums[i], std::make_pair(lookupBelowResult->second.first, lookupAboveResult->second.second));
                start = lookupBelowResult->second.first;
                end = lookupAboveResult->second.second;
            }
            
            longest_len = std::max(end - start + 1, longest_len);
        }
        
        return longest_len;
    }
};