class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) 
    {
        return max(maxHeightOfTriangleHelper(red, blue), maxHeightOfTriangleHelper(blue, red));
    }

private:
    int maxHeightOfTriangleHelper(int ball_a, int ball_b)
    {
        int height = 0;
        int heightBallCount = 1;

        while (ball_a >= 0 && ball_b >= 0)
        {
            ball_a -= heightBallCount;
            if (ball_a < 0)
            {
                return height;
            }
            ++height;
            ++heightBallCount;

            ball_b -= heightBallCount;
            if (ball_b < 0)
            {
                return height;
            }
            ++height;
            ++heightBallCount;
        }

        return height;
    }
};

// https://leetcode.com/problems/maximum-height-of-a-triangle/description/
