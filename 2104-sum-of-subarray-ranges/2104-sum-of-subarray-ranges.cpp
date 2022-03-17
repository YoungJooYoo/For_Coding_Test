class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        const size_t arr_length = nums.size();
        long long sum = 0;
        
        for (size_t i = 0; i < arr_length; i++) {
            int min = nums[i];
            int max = nums[i];
            for (size_t j = i; j < arr_length; j++) {
                if (nums[j] < min) {
                    min = nums[j];
                }
                if (nums[j] > max) {
                    max = nums[j];
                }
                sum += max - min;
            }
        }
        
        return sum;
    }
};

/*

풀이법 :

서브 배열을 2중 for문으로 전체 탐색을 하며
모든 경우의 수를 이용해 구한다.

그 탐색하는 과정에서 최대값, 최속값을 구해
sum에 누적한다.

*/