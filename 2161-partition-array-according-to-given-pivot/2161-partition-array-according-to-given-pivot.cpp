class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> small;
        vector<int> pivots;
        vector<int> big;
        vector<int> result;
        
        for (const auto& num : nums) {
            if (num < pivot) small.push_back(num);
            else if (num == pivot) pivots.push_back(num);
            else if (num > pivot) big.push_back(num);   
        }
        
        for (const auto& elem : small) {
            result.push_back(elem);
        }
        for (const auto& elem : pivots) {
            result.push_back(elem);
        }
        for (const auto& elem : big) {
            result.push_back(elem);
        }
        
        return result;
    }
};