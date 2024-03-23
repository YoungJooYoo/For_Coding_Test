class Solution {
public:
    vector<vector<int>> highFive(const vector<vector<int>>& items) 
    {
        vector<vector<int>> result;
        map<int, vector<int>> mp;

        for (const auto& item : items) {
            const int ID = item[0];
            const int SCORE = item[1];
            mp[ID].push_back(SCORE);
        }

        for (const auto& elem : mp) {
            const int ID = elem.first;
            vector<int> score = elem.second;
            sort(score.begin(), score.end(), greater<int>());
            const int AVG = accumulate(score.begin(), score.begin() + 5, 0) / 5;
            result.push_back({ID, AVG});
        }

        return result;
    }
};

/**

1086. High Five

다양한 학생들의 점수 목록이 주어지는데, 각 항목은 items[i] = [IDi, scorei] 형태로 주어집니다. 이는 IDi를 가진 학생의 한 점수를 나타냅니다. 각 학생의 상위 다섯 평균을 계산합니다.

결과를 IDj가 증가하는 순서대로 정렬된 쌍 배열로 반환합니다. 여기서 result[j] = [IDj, topFiveAveragej]는 IDj를 가진 학생과 그들의 상위 다섯 평균을 나타냅니다.

학생의 상위 다섯 평균은 그들의 상위 다섯 점수의 합을 5로 나눈 것으로 계산됩니다.

예시 1:

입력: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
출력: [[1,87],[2,88]]
설명: 
ID = 1인 학생은 91, 92, 60, 65, 87 및 100 점을 받았습니다. 그들의 상위 다섯 평균은 (100 + 92 + 91 + 87 + 65) / 5 = 87입니다.
ID = 2인 학생은 93, 97, 77, 100 및 76 점을 받았습니다. 그들의 상위 다섯 평균은 (100 + 97 + 93 + 77 + 76) / 5 = 88.6이지만 정수 나눗셈을 사용하여 평균이 88로 변환됩니다.
예시 2:

입력: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
출력: [[1,100],[7,100]]

**/

// https://leetcode.com/problems/high-five/description/
