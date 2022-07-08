class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
    {
        stack<int> s;
        unordered_map<int, int> m;
        vector<int> ans;
        
        for (const int& num : nums) {
            while (s.empty() == false && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        for (const int& n : findNums) {
            ans.push_back(m.count(n) ? m[n] : -1);
        }
        
        return ans;
    }
};