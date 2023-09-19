class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
        unordered_map<long long , int> sums;  //  sum : length, i
        long long cur_sum = 0;
        int max_len = 0;

        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            
            if (cur_sum == k) {  /** case 1 : we get sum k from the start 0 **/ 
                max_len = i + 1;
            } 
            else if (sums.find(cur_sum - k) != sums.end()) { /** case 2 : we find the sum from start point sumed to (cur_sum - k) **/
                max_len = max(max_len, i - sums[cur_sum - k]); // length = i - sums[cur_sum - k])
            }
            
            if (sums.find(cur_sum) == sums.end()) { /** store the cur_sum into the map **/
                sums[cur_sum]= i;
            }
        }

        return max_len;
    }
};

// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/
