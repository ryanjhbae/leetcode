class Solution {
public:

    // this is good and still has O(n) time complexity

    // However, there is an even more efficient solution
    // https://www.cs.utexas.edu/~moore/best-ideas/mjrty/
    int majorityElement(vector<int>& nums) {

        // easy solution: hashmap of number of occurrences
        std::unordered_map<int, int> frequency_table;
        int max_frequency = 0;
        int majority_element;
        int frequency;
        for (int k : nums) {
            auto lookup_result = frequency_table.find(k);
            if (lookup_result == frequency_table.end()) {
                frequency_table[k] = 1;
            } else {
                lookup_result->second += 1;
            }
            
            frequency = frequency_table[k];

            if (frequency > max_frequency) {
                max_frequency = frequency;
                majority_element = k;
            }
        }
        // always assume majority element exists
        return majority_element;
    }
};