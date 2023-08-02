class Solution {
public:
    int minStartValue(vector<int>& nums) 
    {
        int startValue = 1;

        while (true) {
            int total = startValue;
            bool isValid = true;
            for (const int& num : nums) {
                total += num;
                if (total < 1) {
                    isValid = false;
                    break;
                }
            }
            if (isValid == true) {
                return startValue;
            } 
            else {
                startValue++;
            }
        }
        
        return -1;
    }
};
