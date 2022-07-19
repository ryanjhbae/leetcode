class Solution {
public:
    bool isAVowel(char c) {
        
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        
    }
    
    string reverseVowels(string s) {
        
        // constant space and linear time approach
        
        int j = s.length() - 1;
        
        for (int i = 0; i < s.length(); ++i) {
            
            if (j <= i) break;
            
            if (isAVowel(s[i])) {
                
                for (j; j > i; --j) {
                    
                    if (isAVowel(s[j])) {
                        
                        char c = s[i];
                        s[i] = s[j];
                        s[j] = c;
                        --j;
                        break;
                    }
                    
                }
                
            }
            
        }
        return s;
        
    }
};