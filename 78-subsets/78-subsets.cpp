class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res = {{}};
        vector<int> curr;
        
        for (const int& num : nums) {
            size_t array_size = res.size();
            cout << array_size << endl;
            
            for (size_t i = 0; i < array_size; i++) {
                curr = res[i]; // 2차원 배열의 행(일차원배열)을 curr에 대입한다.
                curr.push_back(num);
                res.push_back(curr);
                
                
            }
        }
        
        return res;
    }
};