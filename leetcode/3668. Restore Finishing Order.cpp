class Solution
{
public:
    vector<int> recoverOrder(const vector<int>& order, const vector<int>& friends) const
    {
        assert(!order.empty());
        assert(!friends.empty());           
        assert(friends.size() <= MAX_FRIENDS); 

        vector<int> result;
        result.reserve(friends.size());

        for (const int player : order)
        {
            assert(1 <= player && player <= order.size());
            if (find(friends.begin(), friends.end(), player) != friends.end())
            {
                result.push_back(player);
            }
        }

        assert(result.size() == friends.size()); // 결과는 친구 수와 동일해야 함
        return result;
    }

private:
    enum
    {
        MAX_N = 100,      // 문제 조건: order.length <= 100
        MAX_FRIENDS = 8   // 문제 조건: friends.length <= 8
    };
};


// https://leetcode.com/problems/restore-finishing-order/description/
