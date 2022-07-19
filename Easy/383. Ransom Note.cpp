using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int lookupTable[26];
        
        // why doesn't it work with a char array?? OVERFLOW
        
        for (int i = 0; i < 26; ++i) {
            lookupTable[i] = 0;
            
        }

        for (int i = 0; i < magazine.length(); ++i) {
            char c = magazine[i] - 'a';
            lookupTable[c] += 1;
            #ifdef DEBUG
            std::cout << i << endl;
            std::cout << (int)lookupTable[c] << endl;
            #endif
        }
        

        for (int i = 0; i < ransomNote.length(); ++i) {
            char c = ransomNote[i] - 'a';
            if (lookupTable[c] == 0) {
                #ifdef DEBUG
                std::cout << i << endl;
                std::cout << (int)lookupTable[c] << endl;
                #endif
                return false;
            } else {
                lookupTable[c] -= 1;
            }
        }
        return true;
    }
};