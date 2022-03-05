class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) 
    {
        multiset<int> minHeap;
        vector<int> result;
        
        for (const auto& x : nums) {
            minHeap.insert(a * x * x + b * x + c) ;
        }
        for (const auto& i : minHeap) {
            result.push_back(i);
        }
        
        return result;
    }
};