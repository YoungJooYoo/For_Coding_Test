class Solution 
{
public:
    int countGoodRectangles(const vector<vector<int>>& rectangles) 
    {
        int maxLen = 0;
        int count = 0;
        
        // 가장 큰 정사각형의 변의 길이 찾기
        for (const auto& rectangle : rectangles) 
        {
            const int side = min(rectangle[0], rectangle[1]);
            if (side > maxLen) 
            {
                maxLen = side;
                count = 1;
            } 
            else if (side == maxLen) 
            {
                count++;
            }
        }
        
        return count;
    }
};
// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/
