 class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int water = 0;
        int minHeight = 0;
        
        while (left < right) {
            while (left < right && height[left] <= minHeight) {
                water += minHeight - height[left++];
            }
            while (left < right && height[right] <= minHeight) {
                water += minHeight - height[right--];
            }
            minHeight = min(height[left], height[right]);
        }
        
        return water;
    }
};

/*

풀이법 :

투포인터로 양 끝에서 시작한다.

양 끝에 height로 부터 최소 값을 취합 후,
그 최소 높이를 기준으로 높이를 실시간으로 계산한다.

최소 높이도 계속 갱신한다.

*/