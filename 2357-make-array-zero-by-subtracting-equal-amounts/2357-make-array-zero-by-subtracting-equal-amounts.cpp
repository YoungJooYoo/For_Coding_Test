class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        set<int> unique_num;
        
        for (const auto& num :nums) {
            if (num != 0) {
                unique_num.insert(num);
            }
        }
        
        return unique_num.size();
    }
};