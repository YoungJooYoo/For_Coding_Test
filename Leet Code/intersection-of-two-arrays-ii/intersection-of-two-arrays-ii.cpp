class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> freqency;
        vector<int> result;
        
        for (const int& num : nums1) {
            freqency[num]++;
        }
        for (const int& num : nums2) {
            if (freqency[num] != 0){
                result.push_back(num);
                freqency[num]--;
            }
            
        }
         
        return result;
    }
};

// Solution 2 
/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        size_t i = 0;
        size_t j = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]) { 
                j++;
            }
            else { // nums1[i] < nums2[j]
                i++;
            }
        }
        
        return ans;
    }
};
*/