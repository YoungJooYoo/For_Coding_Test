class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        
        while (low <= high) { // or low < high
            int mid = low + (high - low) / 2;
            
            if (nums[mid] < nums[high]) {
                high = mid;
            }
            else if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else { // nums[mid] == nums[high]
                high--;
            }
        }
        return nums[low];
    }
};

/*
풀이법 :

정렬되어 있는 배열에서 최소 값을 찾는 것이므로
이진탐색을 진행한다.

*/