class Solution {
public:
    int findMin(vector<int> &num) 
    {
        int start = 0;
        int mid;
        int end = num.size() - 1;
        
        while (start < end) {
            mid = (start + end) / 2;
            if (num[start] < num[end]) {
                return num[start];
            }
            if (num[mid] >= num[start]) {
                start = mid + 1;
            } 
            else { // num[mid] < num[start]
                end = mid;
            }
        }
        
        return num[start];
    }
};