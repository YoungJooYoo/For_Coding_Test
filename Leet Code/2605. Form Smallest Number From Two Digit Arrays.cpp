class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        int same_num = INT_MAX;
        int smallest_num = 0;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // 같은숫자 찾기
        for (const auto& num1 : nums1) {
            for (const auto& num2 : nums2) {
                if (num1 == num2) {
                    same_num = min(same_num, num1);
                }
            }
        }

        // 최저숫자 찾기
        set<int> st; // set로 정렬시키기
        st.insert(nums1[0]);
        st.insert(nums2[0]);

        // 가장작은 두숫자를 규칙에 맞게 계산
        auto iter = st.begin();
        smallest_num += *iter;
        smallest_num *= 10;
        iter++;
        smallest_num += *iter;

        return min(same_num, smallest_num);
    }
};

// https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/
