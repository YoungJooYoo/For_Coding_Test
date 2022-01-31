/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) 
    {
        int boundary_out = INT_MAX;
        size_t i = 0;
        
        while (reader.get(i) != boundary_out) {
            if (reader.get(i) == target) {
                return i;
            }
            i++;
        }
        
        return -1;
    }
};