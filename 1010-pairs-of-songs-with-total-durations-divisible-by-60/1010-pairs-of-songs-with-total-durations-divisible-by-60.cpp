class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int, long long int> mp;
        long long int cnt = 0;
        
        // 60으로 나눈 나머지를 hash에 저장.
        for (const int& num : time) {
            mp[num % 60]++;
        }
        
        for (const auto& [first, second] : mp) {
            if (first == 0 || first == 30) {
                cnt += ((second - 1) * second) / 2;
            }
            else if (mp.count(60 - first)) {
                cnt += second * mp[60 - first];
                mp[60 - first] = 0;
            }
        }
        
        return cnt;
    }
};