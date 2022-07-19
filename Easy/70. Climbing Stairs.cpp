class Solution {
    /*
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    */
    
    // essentially the number of integer compositions of n with 1 or 2 as parts
    
    // x + x^2 is the generating series for a single part
    // then the generating series for the whole set of int comps with parts from {1, 2} is going to be
    // 1/(1 - x - x^2)
    
    // see section 4.1 of math 239 course notes for a combinatoric solution
    // but don't do it this way, do it the easy way
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        int oneLessCount = 2;
        int twoLessCount = 1;
        int count;
        int x = 3;
        do {
            // if we know the answer for n - 1 and n - 2, we can just add them bc
            //   for any way for n - 1 steps we can add an extra step at the end, or 2 steps
            //   for n -2
            count = oneLessCount + twoLessCount;
            twoLessCount = oneLessCount;
            oneLessCount = count;
            ++x;
        } while (x <= n);
        
        return count;
    }
};