class Solution {
public:
    int maxProfit(vector<int>& prices){
       int n = prices.size();
       int profit = 0;
       int maxProfit = 0;
       int left = 0;
       int right = left + 1;
       while(right < n){
        
        if(prices[left] > prices[right]){
          left = right;
          right++;  
        } 
        else{
           profit = prices[right] - prices[left];
           maxProfit = max(maxProfit, profit); 
           right++;
        }
       }
       return maxProfit;
    }
};
