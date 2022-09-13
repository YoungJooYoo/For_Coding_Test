class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int result = 0;
        
        for (const auto& operation : operations) {
            if (operation == "++X" or operation == "X++") result++;
            else result--;
        }
        
        return result;
    }
};