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