class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        int a1x = rec1[0];
        int a1y = rec1[1];
        int a2x = rec1[2];
        int a2y = rec1[3];
		
        int b1x = rec2[0];
        int b1y = rec2[1];
        int b2x = rec2[2];
        int b2y = rec2[3];

        return (b1x >= a2x || b1y >= a2y || a1x >= b2x || a1y >= b2y) ? false : true;
    }
};