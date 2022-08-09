class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp(0, k);
        

        
        combine(0, 0, n, k, temp);
        
        return result;
    }
    
    void combine(size_t start, size_t num, size_t n ,size_t k, vector<int>& temp)
    {
        if (num == k) {
            result.push_back(temp);
            return;
        }
        
        for (size_t i = start; i < n; i++) {
            temp.push_back(i + 1);
            combine(i + 1, num + 1, n , k, temp);
            temp.pop_back();
            }
        }
    
private:
    vector<vector<int>> result;
};