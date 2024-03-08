class Solution {
    public:
        string stringShift(string& s, const vector<vector<int>>& shift) 
        {
            int left_amount = 0;
            int right_amount = 0;

            for(const auto& v : shift) {
                v.front() ? right_amount += v.back() : left_amount += v.back();
            }
            
            const int total_shift = abs(right_amount - left_amount) % s.length();
            const int start = right_amount < left_amount ? total_shift : s.length() - total_shift;

            return s.substr(start) + s.substr(0, start);
        }
};

// https://leetcode.com/problems/perform-string-shifts/
