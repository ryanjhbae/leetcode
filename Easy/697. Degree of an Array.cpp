class Solution {
public:
    
    // Initial approach: 
        
        // It's easy to find the degree of array: just keep track
        //  of the frequency of each element in the frequencyMap
        //  AND the maximum frequency so far, and at the end
        //  check the maximum frequency.
        
        // How do we then find the shortest subarray with the same degree?
        
        // Once we find the degree d, we should know the number(s) that occur
        //   d times. We can check the array using another iteration to see 
        //   which of these number(s) has the shortest distance between its
        //   first and last occurrence.
        
        // ------------------------------------------------------------------
        
    // Better approach: use a single loop, but with multiple hashmaps or 
    //                  a tuple as the value in each hashmap.

        // The keys should be the numbers themselves.
        // The values should be:
        //   - their frequency (keep updating this)
        //   - their starting index
        //   - their ending index (keep updating this)
        
        // Then iterate through these at the end? Seems inefficient though
    
        // But it's DECENT

        // A potentially slightly more efficient implementation would be
        //   to store the numbers occurring at each frequency in a set,
        //   and to only go through the largest frequency in the second
        //   loop. However, this seems overly inefficient in terms of
        //   space.
    
    int findShortestSubArray(vector<int>& nums) {
        std::unordered_map<int, std::tuple<int, int, int>> frequencyMap;
        
        int maxDeg = 0;
        int curDeg;
        
        // first iteration: find degree of nums
        for (int i = 0; i < nums.size(); ++i) {
            auto lookupResult = frequencyMap.find(nums[i]);
            if (lookupResult == frequencyMap.end()) {
                frequencyMap.emplace(nums[i], std::make_tuple(1, i, i));
                curDeg = 1;
            } else {
                auto &tuple = lookupResult->second;
                std::get<0>(tuple) += 1;
                curDeg = std::get<0>(tuple);
                std::get<2>(tuple) = i;
            }
            
            
            if (curDeg > maxDeg) {
                maxDeg = curDeg;
            }   
        }
        
        int minSize = nums.size();
        
        // now find the shortest subarray with the same degree
        for (auto i : frequencyMap) {
            
            if (std::get<0>(i.second) != maxDeg) {
                continue;
            }
            int subArraySize = std::get<2>(i.second) - std::get<1>(i.second) + 1;
            if (subArraySize < minSize) {
                minSize = subArraySize;
            }
        }
        
        return minSize;
        
    }
};

// After looking at solutions:

// - You actually don't need to store the ending index. 
// - A smarter way of doing this is to differentiate between curDeg == and 
//   curDeg > maxDeg. This allows you to implement the solution in one pass.
// https://leetcode.com/problems/degree-of-an-array/discuss/124317/JavaC%2B%2BPython-One-Pass-Solution