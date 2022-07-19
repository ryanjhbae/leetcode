class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        int oneBefore = 1;
        int twoBefore = 0;
        int x = 2;
        int fib;
        do {
            fib = oneBefore + twoBefore;
            twoBefore = oneBefore;
            oneBefore = fib;
            x++;
        } while (x <= n);
        return fib;
    }
};