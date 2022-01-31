class Solution {
public:
    int search(const ArrayReader& reader, int target) 
    {
        int start = 0;
        int end = 9999; // 문제 조건 길이가 최대 10000이므로 0 ~ 9999 범위가 배열의 최대 길이다.
        int mid;
        
        while (start <= end) {
            int mid = start + (end - start);
            // int mid = (start + end) / 2;
            if (reader.get(mid) == target) {
                return mid;
            }
            else if (reader.get(mid) < target) {
                start = mid + 1;
            }
            else { // reader.get(mid) > target
                end = mid - 1;
            }
        }
        
        return -1;
    }
};

/* easy solution */
/*
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
*/