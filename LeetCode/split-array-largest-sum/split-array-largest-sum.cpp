class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        if(nums.empty() || m == 0) {
            return 0;
        }
        
        size_t left = 0;
        size_t right = 0;
        
        // left는 가장 작은 min_sum, right는 max_sum
        for (size_t num : nums) {
            left = max(left, num); // 배열의 가장 큰 값highest number i.e the max it'll go incase of m==nums.size()
            right = right + num; // 배열의 총합total sum i.e the max it can go incase of m==1
        }
        if (m == nums.size()) {
            return left; //edge case
        }
        if (m == 1) {
            return right; //edge case
        }
        
        while (left < right)  { //modified binary search w/ search space b/w highestnum...totalsum
            size_t mid = (left + right) / 2;
            size_t curr_bagsize = 0;
            size_t curr_m = 1;
            
            for (const int& num : nums) {
                if (curr_bagsize + num > mid) { // bag m is full, try the next bag now
                    curr_m++; 
                    curr_bagsize = 0;
                }
                curr_bagsize = curr_bagsize + num;
            } 
            if(curr_m > m) //we need a bigger bag size if curr_m > m
                left = mid + 1;
            else //current bag size is sufficient enough, so check for smaller bag sizes
                right = mid;
        }
        
        return left;
    }
};