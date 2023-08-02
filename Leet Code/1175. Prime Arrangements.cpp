class Solution {
public:
    int numPrimeArrangements(int n) 
    {
        const int k = upper_bound(primes.begin(), primes.end(), n) - primes.begin(); // index 반환
        const auto mod = (long long)1e9 + 7;
        long long result = 1;

        for (int i = 2; i <= k; i++) {
            result *= i; 
            result %= mod;
        }
        for (int i = 2; i <= n - k; i++) {
            result *= i; 
            result %= mod;
        }

        return result;
    }

private:
    const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
};

https://leetcode.com/problems/prime-arrangements/description/
