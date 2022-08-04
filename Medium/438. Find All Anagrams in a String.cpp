class Solution {
public:

    // technically O(m * n) due to the clearing...
    vector<int> findAnagrams(string s, string p) {
        // store how many times each character appears in p
        // you don't actually even need a hashmap, since we are guaranteed
        //  lowecase English letters, but it's good to generalize
        unordered_map<char, int> patternMap;
        for (char c : p) {
            patternMap[c]++;
        }
        
        vector<int> anagrams;
        int matchCount = 0; // use this to check if we have found an anagram
        // this is the number of frequencies of our current "candidate"
        //   that match thsoe of p
        // iff matchCount == patternMap.size() we have found an anagram

        int pattern_idx = 0; // 
        
        unordered_map<char, int> anagramMap;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            auto patternLookupResult = patternMap.find(c);
            
            if (patternLookupResult == patternMap.end()) {
                // in this case, no substring containing this character 
                //   can be an anagram of p
                // so...reset our frequency counts for the current substring
                //   and continue
                
                anagramMap.clear(); // reset
                matchCount = 0;
                pattern_idx = 0;
                continue;
            }

            if (pattern_idx == p.size()) {
                char d = s[i - p.size()];
                int anagram_count = anagramMap[d];
                int pattern_count = patternMap[d];
                if (anagram_count == pattern_count) {
                    matchCount--;
                }
                anagramMap[s[i - p.size()]] -= 1;
                if (anagram_count - 1 == pattern_count) {
                    matchCount++;
                }
                
            }

            auto anagramLookupResult = anagramMap.find(c);
            if (anagramLookupResult == anagramMap.end()) {
                anagramLookupResult = anagramMap.emplace(c, 1).first;
            } else {
                anagramLookupResult->second++;
            }
            
            if (anagramLookupResult->second == patternLookupResult->second) {
                matchCount++;
            } else if (anagramLookupResult->second == patternLookupResult->second + 1) {
                matchCount--;
            }
            #if 0
            cout << "i = " << i << endl;
            cout << "a : " << anagramMap['a'] << endl;
            cout << "b : " << anagramMap['b'] << endl;
            cout << "c : " << anagramMap['c'] << endl;
            cout << "pattern_idx = " << pattern_idx << endl;
            cout << "matchCount = " << matchCount << endl;
            cout << "----------------------------" << endl;
            #endif

            if (matchCount == patternMap.size()) {
                anagrams.push_back(i - p.size() + 1);
            }
            if (pattern_idx < p.size()) {
                pattern_idx++;
            }
        }
        return anagrams;
    }
};