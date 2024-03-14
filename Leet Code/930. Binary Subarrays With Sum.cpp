class Solution {
public:
    int numSubarraysWithSum(const vector<int>& nums, const int goal) const 
    {
        int count = 0; // 현재까지의 합이 goal이 되는 경우의 수를 저장하는 변수
        int pre_sum = 0; // 현재까지의 누적 합을 나타내는 변수
       
        unordered_map<int, int> mp; // 누적 합을 저장할 해시 맵
        mp[0] = 1;  // 초기값 설정: 0이라는 누적 합이 1번 나타남
        
        for (const auto num : nums) { // 입력 배열 nums를 반복하면서 누적 합을 계산
            pre_sum += num; // 현재 원소를 누적 합에 더함
            const int to_remove = pre_sum - goal; // 목표값에서 현재까지의 누적 합을 뺀 값을 계산
            
            // 이전에 나타난 누적 합 중 목표값과의 차이가 to_remove인 경우의 수를 세어 count에 추가
            if (mp.count(to_remove) != 0) {
                count += mp[to_remove];
            }
            ++mp[pre_sum]; // 현재 누적 합을 해시 맵에 추가하면서 나타난 횟수를 증가
        }
        
        return count;
    }
};

// https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14
