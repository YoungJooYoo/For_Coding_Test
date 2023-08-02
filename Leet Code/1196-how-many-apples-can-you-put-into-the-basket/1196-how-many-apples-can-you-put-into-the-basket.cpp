class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) 
    {
        int sum = 5000;
        int count = 0;
        
        sort(weight.begin(), weight.end());
        
        for (const auto& elem : weight) {
            sum -= elem;
            count++;
            if (sum == 0) {
                return count;
            }
            else if (sum < 0) {
                return count - 1;
            }
        }
        
        return count;
    }
};