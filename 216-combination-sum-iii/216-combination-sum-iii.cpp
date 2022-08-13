class Solution 
{
public:
    void recursive(int k, int n, int i)
    {
        if (temp.size() == k && n == 0) {
            
            result.push_back(temp);
            
            return;
        }
        for(int j=i;j<10;j++)
        {
            temp.push_back(j);
            recursive(k,n-j,j+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        recursive(k,n,1);
        return result;
    }
    
private:
    vector<vector<int>> result;
    vector<int> temp;
};