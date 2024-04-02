class Solution {
public:
    int minimumBoxes(const vector<int>& apple, vector<int>& capacity) 
    {
        int result = 0;
        const int TOTAL_APPLE = accumulate(apple.begin(), apple.end(), 0);
        
        sort(capacity.begin(), capacity.end(), greater<int>());

        const size_t CAP_LEN = capacity.size();
        int sum = 0;
        for (int i = 0; i < CAP_LEN; ++i) {
            sum += capacity[i];
            if (sum >= TOTAL_APPLE) {
                return i + 1;
            }
        }

        return 0;
    }
};

// https://leetcode.com/problems/apple-redistribution-into-boxes/
