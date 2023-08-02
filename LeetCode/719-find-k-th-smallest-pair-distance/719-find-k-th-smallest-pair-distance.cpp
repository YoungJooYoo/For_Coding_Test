class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        const size_t nums_length = nums.size();
        int start = 0; // 일반적인 이진탐색의 인덱스가 아닌, 이번에는 거리로 쓴 것
        int mid;
        int end = 1000000;
        int cnt;
        
        sort(nums.begin(), nums.end());
        
        /* 2진탐색으로  찾기 */
        while (start < end) {
            mid = (start + end) / 2;
            cnt = 0;
            for (size_t i = 0, j = 0; i < nums_length; i++) {
                while (j < nums_length && nums[j] - nums[i] <= mid) {
                    j++;
                }
                cnt = cnt + j - i - 1;
            }
            if (cnt < k) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        return start;
    }
};

/*
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        int min = INT_MAX;
        vector<int> distance;
        
        sort(nums.begin(), nums.end());
        
        for (size_t i = 0, j = 0; i < nums.size() - 1; i++) {
            distance.push_back(abs(nums[i] - nums[j]));
            j++;
        }
        
        for (const int& element : distance) {
            if (abs(element - k) < min) {
                min = abs(element - k);
            }
        }
        
        return min;
    }
};

*/