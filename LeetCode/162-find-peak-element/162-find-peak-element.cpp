class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int left = 0;
        int mid;
        int right = nums.size() - 1;
        
        while(left < right) {
            mid = (left + right) / 2; // or mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;    
            }
            else { 
                left = mid + 1;
            }
        }
        
        return left;
    }
};

/*
풀이법 :
정렬되지 않은 배열에서 최대값의 인덱스를 반환하는 문제이다.
시간은 log(n) => 이진탐색 하라는 의미

중간값 기준으로,  왼쪽은 정렬되지 않았지만 작은, 오른쪽은 정렬되지 않았지만 큰 값

*/