class Solution {
public:
    
    // a very inefficient solution (but hopefully it works) (actually beats 100% on time, but it IS very messy)
    // target here is actually the amount we need to add to candidate to
    // sum to the original target
    void addCombos(vector<vector<int>> &combinations, vector<int> &candidates, vector<int>          
                   candidate, int target, int startingIndex) {
        for (int i = startingIndex; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                return;
            } else if (candidates[i] == target) {
                candidate.push_back(target);
                combinations.push_back(candidate);
                return;
            }
            
            int maxElementCount = target / candidates[i];
            if (target % candidates[i] != 0) {
                maxElementCount -= 1;
            }
            
            for (int j = 1; j <= maxElementCount; ++j) {
                candidate.push_back(candidates[i]);
                int needToMake = target - j * candidates[i];
                if (needToMake == 0) {
                    combinations.push_back(candidate);
                    break;
                }
                addCombos(combinations, candidates, candidate, needToMake, i + 1);
            }
            candidate.resize(candidate.size() - maxElementCount);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // sorting candidates makes it easier for us to not add duplicate combinations
        // to our return vector<vector<int>>
        // in all combinations the elements will be in ascending order
        
        vector<vector<int>> combinations;
        
        for (int i = 0; i < candidates.size(); ++i) {
            if (candidates[i] > target) break; // candidates[i] >= 1 as per the description
            int maxElementCount = target / candidates[i];
            if (target % candidates[i] != 0) {
                // then it doesn't split cleanly and we actually can't have maxElementCount
                //   count of candidates[i] in any combination since then we would need
                //   a number less than candidates[i] to make it sum to target
                maxElementCount -= 1;
            }
            vector<int> candidate;
            for (int j = 1; j <= maxElementCount; ++j) {
                candidate.push_back(candidates[i]);
                int needToMake = target - j * candidates[i];
                if (needToMake == 0) {
                    combinations.push_back(candidate);
                    break;
                }
                
                addCombos(combinations, candidates, candidate, needToMake, i + 1);
            }
        }
        return combinations;
    }
};