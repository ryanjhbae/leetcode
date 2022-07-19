class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digitCount = digits.size();
        for (int i = digitCount - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                digits[i] += 1;
                break;
            } else if (i == 0) {
                digits[i] = 0;
                // if it's the first digit, we'll need to resize
                // i don't think there's any way of checking for
                // resizing other than going through the whole array 
                // so it doesn't matter that we do this
                digits.resize(digitCount + 1);
                for (int j = digitCount; j > 0; --j) {
                    digits[j] = digits[j - 1];
                }
                digits[0] = 1;
                break;
            } else {
                digits[i] = 0;
            }
        }
        return digits;
    }
};