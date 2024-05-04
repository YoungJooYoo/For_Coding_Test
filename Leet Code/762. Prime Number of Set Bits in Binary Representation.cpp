class Solution {
public:
    bool is_prime(int n) 
    {
        if (n <= 1) return false;

        for (uint i = 2; i < n; ++i) {
            if (n % i == 0) return false;
        }

        return true;
    }

    int countPrimeSetBits(const int left, const int right) 
    {
        int count = 0;

        for (int i = left; i <= right; ++i) {
            const string binary = bitset<32>(i).to_string();
            int cnt = 0;
            for (const auto ch : binary) {
                if (ch == '1')  ++cnt;
            }
            if (is_prime(cnt) == true) ++count;
        }

        return count;
    }
};
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
