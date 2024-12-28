// * brute force 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        for(int buy=0;buy<prices.size();buy++){
            for(int sell=buy+1;sell<prices.size();sell++){
                // calculate current profit 
                int profit=prices[sell]-prices[buy];
                max_profit=max(profit,max_profit);
            }
        }
        return max_profit;
    }
};

// * optimal 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int min_price=INT_MAX;
        for(auto price:prices){
            min_price=min(price,min_price); // get min price 
            // calculate profit 
            max_profit=max(max_profit,price-min_price);
        }
        return max_profit;

    }
};