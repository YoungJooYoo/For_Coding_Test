class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int direction = RIGHT;
        int pos = 1;

        while (time-- != 0) {
            if (direction == RIGHT) ++pos;
            else if (direction == LEFT) --pos;
            if (pos == 1 or pos == n) direction = !direction;
        }

        return pos;
    }
    
private:
    enum { 
        LEFT = 0,
        RIGHT = 1
    };
};

// https://leetcode.com/problems/pass-the-pillow/description/
