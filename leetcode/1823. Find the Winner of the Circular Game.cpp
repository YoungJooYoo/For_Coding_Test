class Solution
{
public:
    int findTheWinner(const int n, const int k) const
    {
        assert(MIN_VAL <= n && n <= MAX_VAL);
        assert(MIN_VAL <= k && k <= MAX_VAL);

        vector<int> circle;

        for (int i = 1; i <= n; ++i)
        {
            circle.push_back(i);
        }

        return findWinnerRecursive(circle, k, 0);
    }

private:
    int findWinnerRecursive(vector<int>& circle, const int k, const int idx) const
    {
        if (circle.size() == 1)
        {
            return circle.front();
        }

        const int currentIDX = (idx + k - 1) % static_cast<int>(circle.size());
        circle.erase(circle.begin() + currentIDX);

        return findWinnerRecursive(circle, k, currentIDX); // 다음 시작점은 idx 그대로
    }

    enum
    {
        MIN_VAL = 1,
        MAX_VAL = 500
    };
};


// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
