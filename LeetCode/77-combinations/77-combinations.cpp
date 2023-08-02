class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp(0, k);
        
        recursive(0, 0, n, k, temp);
        
        return result;
    }
    
    void recursive(int start, int num, int n, int k, vector<int>& temp)
    {
        if (num == k) {
            result.push_back(temp);
            return;
        }
        
        for (size_t i = start; i < n; i++) {
            temp.push_back(i + 1);
            recursive(i + 1, num + 1, n , k, temp);
            temp.pop_back();
            }
        }
    
private:
    vector<vector<int>> result;
};