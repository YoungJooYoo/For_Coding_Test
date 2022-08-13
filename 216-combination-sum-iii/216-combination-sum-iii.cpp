class Solution 
{
public:
    void recursive(int k, int n, int index)
    {
        if (temp.size() == k && n == 0) {
            result.push_back(temp);
            return;
        }
        
        for (int i = index; i < 10; i++) {
            temp.push_back(i);
            recursive(k, n - i, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        recursive(k, n, 1); // k, n, 1부터 시작
        return result;
    }
    
private:
    vector<vector<int>> result;
    vector<int> temp;
};