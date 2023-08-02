class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        map<int, int> freq;
        vector<vector<int>> result;

        for (const auto& num : nums) freq[num]++; // 각 원소가 나오는 횟수를 기록

        size_t zero_count = 0;
        while (true) { // 원소를 배열에 넣을때마다, 원소의 카운트를 감소 시킴, 남은 원소가 없으면 반복분 종료
            vector<int> temp;
            for (auto& elem : freq) { // 원소가 존재하면 배열에 넣는다.
                if (elem.second > 0) {
                    temp.push_back(elem.first);
                    --elem.second;
                }
                else if (elem.second == 0) ++zero_count;
            }
            if (temp.size() > 0) result.push_back(temp);
            if (zero_count == freq.size()) return result; // 모든 원소가 비었다면 종료
            else zero_count = 0;
        }


        return result;
    }
};

https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
