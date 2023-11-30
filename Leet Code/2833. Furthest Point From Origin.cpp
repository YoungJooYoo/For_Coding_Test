class Solution {
public:
    int furthestDistanceFromOrigin(const string& moves) 
    {
        size_t count_L = 0;
        size_t count_R = 0;
        size_t count_under_bar = 0;
        
        for (const auto& move : moves) {
            if (move == 'L') ++count_L;
            else if (move == 'R') ++count_R;
            else ++count_under_bar;
        }

        return count_under_bar + max(count_L, count_R) - min(count_L, count_R);
    }
};

// moves의 각 원소의 총합이 가장 큰 것을 구하면 된다.
// https://leetcode.com/problems/furthest-point-from-origin/description/
