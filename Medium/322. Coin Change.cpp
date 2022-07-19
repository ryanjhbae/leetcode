class Solution {
public:
    const int impossible = -1;
    vector<int> fewestCoins;
    // dynamic programming using tabulation
    
    // O(nm + mlogm) time (n = amount, m = coins.size()), O(n) space
    int coinChange(vector<int>& coins, int amount) {
        fewestCoins.resize(amount + 1, 0); // amount + 1 for convenient indexing
        std::sort(coins.begin(), coins.end()); // pretty necessary
        
        int j = 0;
        
        for (int i = 1; i <= amount; ++i) {
            if (i < coins[0]) {
                fewestCoins[i] = impossible;
                continue;
            } 

            int k = j;
            // since the next i will be bigger
            while (coins[j] == i && j < coins.size() - 1) {
                j++;
            }
            
            // find the largest coin that fits and allows
            //  for change
            while (coins[k] > i) {
                k--;
            }
            int minCoinCount = impossible;
            while (k >= 0) {
                if (fewestCoins[i - coins[k]] != impossible) {
                    if (minCoinCount == impossible || 
                       fewestCoins[i - coins[k]] < minCoinCount) {
                        minCoinCount = fewestCoins[i - coins[k]];
                    }
                }
                k--;
            }
            if (minCoinCount == impossible) {
                fewestCoins[i] = impossible;
            } else {
                fewestCoins[i] = minCoinCount + 1;
            }
             
        }
        return fewestCoins[amount];
    }
    
    #if 0
    // dynamic programming solution using memoization
    
    int coinChangeRecursive(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (fewestCoins[amount] != 0) {
            return fewestCoins[amount];
        } else {
            int i = coins.size() - 1;
            // int min_count = -1;
            
            while (i >= 0 && coins[i] <= amount) {
                int coinCount = coinChangeRecursive(coins, amount - coins[i]);
                if (coinCount != -1) {
                    cout << coins[i] << endl;
                    return coinCount + 1;
                } else {
                    --i;
                }
            }
            return -1;
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        fewestCoins.resize(amount + 1, 0); // for convenient indexing
        std::sort(coins.begin(), coins.end());
        return coinChangeRecursive(coins, amount);
    }
    
    
    // actually, greedy does not work
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        // classic greedy algorithm problem
        int i = coins.size() - 1;
        int coinCount = 0;
        while (i >= 0) {
            while (coins[i] <= amount) {
                amount -= coins[i];
                coinCount++;
            }
            i--;
        }
        if (amount != 0) {
            return impossible;
        } else {
            return coinCount;
        }
    }
    #endif
};