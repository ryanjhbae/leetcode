class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // return the maximum difference (but the selling price
        //   must be after the buying price in the array)
        
        
        // O(n) solution
        // for each element, compare it to the minimum element so far
        int min = prices[0];
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            
            if (prices[i] < min) {
                min = prices[i];
            } else {
                int profit = prices[i] - min;
                if (profit > max_profit) {
                    max_profit = profit;
                }
            }
        }
        return max_profit;
        
        #if 0
        // slightly faster O(n^2) solution
        int max_profit = 0;
        int buy_idx = 0;
        int sell_idx = 1;
        for (int i = 0; i < prices.size(); ++i) {
            // assuming that we scanned the rest of the array with buy_price
            //   as our buying price, there is no way to get a higher
            //   profit with a higher buying price
            
            if (i == 0 || i >= sell_idx) {
                
                for (int j = i + 1; j < prices.size(); ++j) {
                    int profit = prices[j] - prices[i];
                    if (profit > max_profit) {
                        max_profit = profit;
                        buy_idx = i;
                        sell_idx = j;
                    }
                }
                
            } else if (prices[i] >= prices[buy_idx]) {
                continue;
            } else {
                buy_idx = i;
                max_profit = prices[sell_idx] - prices[buy_idx];
            }
        }
        if (prices.size() <= 1) {
            return max_profit;
        } else {
            return std::max(max_profit, prices[sell_idx] - prices[buy_idx]);
        }
        
        #endif
        
        #if 0
        // monke O(n^2) solution
        int max_profit = 0;
        int buy_price = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            // assuming that we scanned the rest of the array with buy_price
            //   as our buying price, there is no way to get a higher
            //   profit with a higher buying price
            if (prices[i] > buy_price) {
                continue;
            }
            for (int j = i + 1; j < prices.size(); ++j) {
                int profit = prices[j] - prices[i];
                if (profit > max_profit) {
                    max_profit = profit;
                    buy_price = prices[i];
                }
            }
        }
        return max_profit;
        #endif
    }
};