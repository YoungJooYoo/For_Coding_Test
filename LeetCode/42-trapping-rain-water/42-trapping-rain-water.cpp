 class Solution 
{
public:
    int trap(vector<int> height)
    {
        int left = 0;
        int right = height.size() - 1;
        int min_height = 0;
        int area = 0;

        while (left < right)
        {
            while (left < right && height[left] <= min_height)
            {
                area += min_height - height[left];
                left++;

            }
            while (left < right && height[right] <= min_height) 
            {
                area += min_height - height[right];
                right--;
            }

            min_height = min(height[left], height[right]);
        }
        
        return area;
    }   
};

/*

풀이법 :

투포인터로 양 끝에서 시작한다.

양 끝에 height로 부터 최소 값을 취합 후,
그 최소 높이를 기준으로 높이를 실시간으로 계산한다.

최소 높이도 계속 갱신한다.

*/