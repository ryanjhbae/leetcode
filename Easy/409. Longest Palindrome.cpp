class Solution {
public:
    int longestPalindrome(string s) {
        // faster method (still O(n) but faster in practice)
        // store the whether each character occurs an odd or even number of times
        
        // true iff the corresponding element occurs an odd number of times
        bool odd_freq[52] = {0};
        int maxlen = 0;
        int odd_count = 0;
        for (char c : s) {
            maxlen++;
            int idx;
            if ('A' <= c && c <= 'Z') {
                idx = c - 'A';
            } else {
                idx = 26 + c - 'a';
            }
            odd_freq[idx] = !odd_freq[idx];
            if (odd_freq[idx]) {
                odd_count += 1;
            } else {
                odd_count -= 1;
            }
        }
        cout << odd_count;
        maxlen -= odd_count;
        if (odd_count != 0) {
            maxlen++;
        }
        
        #if 0
        for (char &c : s) {
            if ('A' <= c && c <= 'Z') {
                frequencyMap[(c - 'A')]++;
            } else {
                frequencyMap[26 + (c - 'a')]++;
            }
        }
    
        bool odd_freq_exists = false;
        
        // go through the entire frequencyMap 
        // if the frequency is even, we can immediately add it to the length 
        //   (since we can just place it at the start and end of the existing palindrome)
        
        // if the frequency is odd, we cannot add it unless it is the maximum odd frequency
        //   (any letter occurring an odd number of times has to appear in the middle
        //   of the palindrome) 
        //   we can only make a palindrome using freq - 1 letters
        
        for (int i = 0; i < 52; ++i) {
            int freq = frequencyMap[i];
            
            if (freq % 2 == 0) {
                maxlen += freq;
            } else {
                maxlen += freq - 1;
                odd_freq_exists = true;
            }
        }
        // if there is a letter occurring an odd number of times, simply add 1 at the end
        // (we can just insert one copy of it in the middle at the end)
        if (odd_freq_exists) {
            maxlen++;
        }
        #endif
        return maxlen;
    }
};