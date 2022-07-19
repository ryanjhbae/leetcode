class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.length() - 1;
        bool word_started = false;
        while (i >= 0) {
            if (s[i] != ' ') {
                word_started = true;
            }
            if (word_started) {
                if (s[i] != ' ') {
                    len += 1;
                } else {
                    break;
                }
            }
            --i;
        }
        return len;
    }
};