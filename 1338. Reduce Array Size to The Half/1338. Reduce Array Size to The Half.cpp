class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        const size_t ARR_SIZE = arr.size();
        const size_t HALF_SIZE = ARR_SIZE / 2;
        unordered_map<int, int> freq;
        priority_queue<int> q;
        int result = 0;
        int removed = 0;

        for (const auto& num : arr) {
            freq[num]++;
        }
        for (const auto& num : freq) {
            q.push(num.second); // 내림차순으로 정렬.
        }
        
        // 우선순위 큐에 가장 빈번한 숫자 갯수부터 내림차순 정렬 되어 있다
        while (removed < HALF_SIZE) {
            removed += q.top();
            q.pop();
            result++;
        }
        
        return result;
    }
};

// https://leetcode.com/problems/reduce-array-size-to-the-half/description/
