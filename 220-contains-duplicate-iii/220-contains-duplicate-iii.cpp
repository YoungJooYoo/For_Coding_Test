class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        const size_t nums_length = nums.size();
        
        if(nums_length == 0 || k < 0  || t < 0) {
            return false;
        }

        unordered_map<int,int> buckets;
        
        for (size_t i = 0; i < nums_length; ++i) {
            int bucket = nums[i] / ((long)t + 1);
            
			// For negative numbers, we need to decrement bucket by 1
			// to ensure floor division.
			// For example, -1/2 = 0 but -1 should be put in Bucket[-1].
			// Therefore, decrement by 1.
            if (nums[i] < 0) {
                bucket--;
            }
            
            if (buckets.find(bucket) != buckets.end()) {
                return true;
            }
            else {
                buckets[bucket] = nums[i];
                if (buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= t) {
                    return true;
                }
                if (buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= t) {
                    return true;
                }
                if (buckets.size() > k) {
                    int key_to_remove = nums[i-k] / ((long)t + 1);
                    if (nums[i-  k] < 0) {
                        key_to_remove--;
                    }
                    buckets.erase(key_to_remove);
                }
            }
        }
        
        return false;
    }
};