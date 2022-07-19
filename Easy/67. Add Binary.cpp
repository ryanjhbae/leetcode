class Solution {
public:

    string addBinary(string a, string b) {
        string sum;
        int max = std::max(a.length(), b.length());
        sum.resize(max);
        int carry = 0;
        int sum_digit, a_digit, b_digit;
        for (int i = 0; i < max; ++i) {

            if (i < a.length()) {
                a_digit = a[a.length() - 1 - i] - '0';
            } else {
                a_digit = 0;
            }

            if (i < b.length()) {
                b_digit = b[b.length() - 1 - i] - '0';
            } else {
                b_digit = 0;
            }
            
            sum_digit = a_digit + b_digit + carry;

            if (sum_digit % 2 == 0) {
                sum[max - 1 - i] = '0';
            } else {
                sum[max - 1 - i] = '1';
            }

            if (sum_digit < 2) {
                carry = 0;
            } else {
                carry = 1;
            }
        }

        if (carry != 0) {
            sum = '1' + sum;
        }
        return sum;
    }
};