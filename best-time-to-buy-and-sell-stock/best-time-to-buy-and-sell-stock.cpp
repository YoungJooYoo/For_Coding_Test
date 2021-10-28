class Solution {
   public:
     int maxProfit(vector<int>& prices) {
         int min = INT_MAX;
         int max_profit = 0;
            
         for(size_t i = 0; i < prices.size(); i++){
             if(prices[i] < min) {
                min = prices[i]; // 최소값 찾으면, 이 최소값부터 뒤에 원소랑 비교해서 답 찾기
             }
             max_profit = max(max_profit, prices[i] - min);
         }
         
         return max_profit;
     }
};
