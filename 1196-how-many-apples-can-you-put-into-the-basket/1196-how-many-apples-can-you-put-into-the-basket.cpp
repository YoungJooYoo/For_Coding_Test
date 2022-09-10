class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) 
    {
        int sum = 5000;
        int count = 0;
        
        sort(weight.begin(), weight.end());
        
        for (size_t i = 0; i < weight.size(); i++) {
            sum -= weight[i];
            count++;
            cout << sum << endl;
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