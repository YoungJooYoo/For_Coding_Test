class Solution 
{
public:
    int search(const vector<int>& nums, const int target) const
    {
        assert (MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);
        const int pivotIndex = findPivot(nums);
        const int foundIndexLeftSide = binarySearch(nums, target, 0, pivotIndex - 1);
        const int foundIndexRightSide = binarySearch(nums, target, pivotIndex, nums.size() - 1);

        if (foundIndexLeftSide != FAIL)
        {
            return foundIndexLeftSide;
        }
        else if (foundIndexRightSide != FAIL)
        {
            return foundIndexRightSide;
        }  
    
        return FAIL;
    }

private:
    int findPivot(const vector<int>& nums) const
    {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high)
        {
            const int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
    
    int binarySearch(const vector<int>& nums, const int target, int start, int end) const
    {
        int low = start;
        int high = end;
        
        while (low <= high)
        {
            const int mid = low + (high - low) / 2;
            assert(MIN_VALUE <= nums[low] && nums[low] <= MAX_VALUE);
            assert(MIN_VALUE <= nums[high] && nums[high] <= MAX_VALUE);
            assert(MIN_VALUE <= nums[mid] && nums[mid] <= MAX_VALUE);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else // nums[mid] < target
            {
                low = mid + 1;
            }
        }
        
        return FAIL;
    }

private:
    enum 
    {
        FAIL = -1,
        MIN_LENGTH = 1,
        MAX_LENGTH = 5000,
        MIN_VALUE = -10000,
        MAX_VALUE = 10000,
    };
};

/*
33. 회전된 정렬 배열에서 검색

오름차순으로 정렬된(값들이 모두 서로 다른) 정수 배열 nums가 주어집니다.

함수에 전달되기 전에, nums는 알 수 없는 피벗 인덱스 k (1 ≤ k < nums.length)에서 회전되었을 수 있습니다. 즉, 회전 후 배열은 다음과 같은 형태를 가집니다:
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-인덱스 기준)
예를 들어, [0,1,2,4,5,6,7] 배열이 피벗 인덱스 3에서 회전하면 [4,5,6,7,0,1,2]가 될 수 있습니다.

회전된 배열 nums와 정수 target이 주어질 때, 만약 target이 nums 내에 존재하면 해당 인덱스를 반환하고, 존재하지 않으면 -1을 반환하세요.

알고리즘의 시간 복잡도는 O(log n)이어야 합니다.
*/
