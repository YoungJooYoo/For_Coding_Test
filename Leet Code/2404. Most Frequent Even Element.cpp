class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        unordered_map<int ,int> even_freq;
        
        for (const auto& num : nums) {
            if (num % 2 == 0) even_freq[num]++;
        }

        int max_freq = 0;
        int max_even = -1;
        for (const auto& even : even_freq) { // 최대 빈도 찾음
            max_freq = max(max_freq, even.second);           
        }

        vector<int> max_evens;
        for (const auto& even : even_freq) { // 최대 빈도에 해당 짝수 찾음
            if (even.second == max_freq) max_evens.push_back(even.first);
        }

        sort(max_evens.begin(), max_evens.end()); // 최대빈도의 짝수들을 정렬해서 최소값을 구함

        return max_evens.size() == 0 ? -1 : max_evens[0]; // 짝수가 존재하지 않으면 -1, 존재하면 최소값 반환
    }
};

// https://leetcode.com/problems/most-frequent-even-element/description/
