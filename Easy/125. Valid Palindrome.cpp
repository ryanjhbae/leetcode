class Solution {
public:

    bool isUpperCase(char c) {
        return 'A' <= c && c <= 'Z';
    }

    bool isLowerCase(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool isNumeric(char c) {
        return '0' <= c && c <= '9';
    }

    bool isAlphaNumeric(char c) {
        return isUpperCase(c) || isLowerCase(c) || isNumeric(c);
    }

    bool isSameLetter(char b, char c) {
        if (b == c) {
            return true;
        }
        if (isUpperCase(b)) {
            b -= 'A';
            b += 'a';
        }
        if (isUpperCase(c)) {
            c -= 'A';
            c += 'a';
        }
        return b == c;
    }

    bool isPalindrome(string s) {
        // the catch here is that you're trying to determine whether
        //   the string is a palindrome AFTER converting all uppercase
        //   letters into lowercase letters and removing all non-alphanumeric
        //   characters

        // so you'll need to do a bit more work

        int i = 0, k = s.length() - 1;

        while (i < k) {
            while (k > 0 && !isAlphaNumeric(s[k])) {
                --k;
            }

            while (i < s.length() && !isAlphaNumeric(s[i])) {
                ++i;
            }
            if (i >= k) break;
            if (!isSameLetter(s[i], s[k])) {
                return false;
            } else {
                ++i;
                --k;
            }
        }
        return true;
    }
};