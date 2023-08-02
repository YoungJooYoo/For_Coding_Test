class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int count = 0;

        for (size_t i = 0; i < arr1.size(); ++i) {
            bool found = false;
            for (size_t j = 0; j < arr2.size() && found == false; ++j) {
                if (abs(arr1[i] - arr2[j]) <= d) found = true;
            }
            if (found == false) { // arr1[i] - arr2[j] <= d 인 케이스만 카운트하기
                ++count;
            }
        }

        return count;    
    }
};


// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
