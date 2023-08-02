class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) 
 	{
        vector<string> result;
		const size_t nums_length = nums.size();
		int begin;
		int end;
        
        for (size_t i = 0; i < nums_length; i++) {    
            begin = nums[i];
            while (i < (nums_length - 1) && nums[i] ==  nums[i + 1] - 1) {
				i++;
			} // nums_length - 1 마지막 원소전까지
            end = nums[i]; // 마지막 원소
            if (begin == end) {
				result.push_back(to_string(begin));
			}
            else {
				result.push_back(to_string(begin)  + "->" + to_string(end));
			}   
        }
        
        return result;
    }
};