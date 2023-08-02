class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        map<int, string, greater<int>> people; // map을 내림 차순으로 정렬
        vector<string> result;

        size_t i = 0;
        for (const auto& height : heights) { // 키-사람으로 매핑
            people[height] = names[i++];
        }

        for (const auto& person : people) {
            result.push_back(person.second);
        }

        return result;
    }
};

// https://leetcode.com/problems/sort-the-people/description/
