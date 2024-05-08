class Solution 
{
public:
    bool lemonadeChange(const vector<int>& bills) 
    {
        int numFives = 0; // $5 지폐 개수
        int numTens = 0; // $10 지폐 개수
        
        for (const int bill : bills) 
        {
            if (bill == 5) 
            {
                ++numFives;
            } 
            else if (bill == 10) 
            {
                // $10를 받으면 $5를 거슬러 주어야 함
                if (numFives == 0) return false;
                --numFives;
                ++numTens;
            } 
            else if (bill == 20) 
            {
                // $20를 받으면 $10과 $5를 거슬러 주거나 $5를 3장 거슬러 주어야 함
                if (numTens > 0 && numFives > 0) 
                {
                    numTens--;
                    numFives--;
                } 
                else if (numFives >= 3) 
                {
                    numFives -= 3;
                } 
                else 
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

// https://leetcode.com/problems/lemonade-change/description/
