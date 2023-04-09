class Solution {
public:
    int findComplement(int num) 
    {
        size_t mask = ~0; // 1111 1111
        while ((num & mask) != 0) mask = mask << 1; 
  
        return ~mask ^ num;
    }
};

// https://leetcode.com/problems/number-complement/description/
