class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        // O(n) solution (1 pass)
        // use the assumption that 
        int frequencyMap[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            frequencyMap[s[i] - 'a'] += 1;
            frequencyMap[t[i] - 'a'] -= 1;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (frequencyMap[i] != 0) {
                return false;
            }
        }
        return true;
        #if 0 
        // O(n) solution (2 passes)
        if (s.length() != t.length()) return false;
        std::unordered_map<char, int> frequencyMap;
        // use a hashmap to track the frequencies of each character in s
        for (char c : s) {
            auto lookupResult = frequencyMap.find(c);
            if (lookupResult == frequencyMap.end()) {
                frequencyMap.emplace(c, 1);
            } else {
                lookupResult->second += 1;
            }
        }
        for (char c : t) { 
            auto lookupResult = frequencyMap.find(c);
            if (lookupResult == frequencyMap.end()) {
                return false;
            } else if (lookupResult->second == 0) {
                return false;
            } else {
                lookupResult->second -= 1;
            }
        }
        return true;
        #endif 
    }
};