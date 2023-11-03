class Solution {
public:
    int secondHighest(const string& s) 
    {
        set<int, greater<int>> nums;

        for (const auto& ch : s) {
            if (isdigit(ch) == true) {
                nums.insert(ch - '0');
            }
        }
        
        if (nums.size() < 2) {
            return NOT_EXIST;
        }

        auto itr = nums.begin();
        ++itr;
        return *itr;
    }

private : 
    enum { NOT_EXIST = -1 };
};

// https://leetcode.com/problems/second-largest-digit-in-a-string/description/
