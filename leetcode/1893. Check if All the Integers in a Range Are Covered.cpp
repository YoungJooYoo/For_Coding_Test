class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, const int left, const int right) 
    {
        set<int> st;

        // rage 만큼의 숫자 범위를 만든다.
        for (const auto& range : ranges) {
            const int start = range[0];
            const int end = range[1];
            for (size_t i = start; i <= end; ++i) {
                st.insert(i);
            }
        }

        // 위에 만든 set안에  left부터 right의 모든 범위가 존재하는지 체크한다.
        for (size_t i = left; i <= right; ++i) {
            if (st.find(i) == st.end()) return false;
        }

        return true;
    }
};
