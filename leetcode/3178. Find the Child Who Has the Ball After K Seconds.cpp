class Solution 
{
public:
    int numberOfChild(int n, int k) 
    {
        int position = 0;
        int direction = RIGHT;
    
        for (int i = 0; i < k; ++i) 
        {
            position += direction;
        
            if (position == n - 1) 
            {
                direction = LEFT;
            } 
            else if (position == 0) 
            {
                direction = RIGHT;
            }
        }
    
        return position;
    }

private:
    enum 
    {
        LEFT = -1,
        RIGHT = 1,      
    };
};

// https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/
