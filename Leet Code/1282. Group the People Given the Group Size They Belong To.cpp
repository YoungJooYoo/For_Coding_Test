class Solution {
public:
    vector<vector<int>> groupThePeople(const vector<int>& groupSizes) 
    {
        unordered_map<int, vector<int>> groupMap;
        vector<vector<int>> result;

        for (size_t i = 0; i < groupSizes.size(); i++) {
            groupMap[groupSizes[i]].push_back(i);
        }

        for (const auto& group : groupMap) {
            const int groupSize = group.first;
            const vector<int>& members = group.second;
            const size_t numGroups = members.size() / groupSize; // 그룹이 몇개 나올지 구함
            for (size_t i = 0, index = 0; i < numGroups; ++i) { // members.size()수만큼 반복문을 2중으로 돌린다. 그룹의 총 갯수 * 한 그룹내부의 원소수
                vector<int> currentGroup;
                for (size_t j = 0; j < groupSize; ++j, ++index) {
                    currentGroup.push_back(members[index]);
                }
                result.push_back(currentGroup);
            }
        }

        return result;
    }
};


https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/

/*

번역:
"1282. 그룹 크기에 따른 사람들 그룹화하기"
n명의 사람들이 알 수 없는 수의 그룹으로 나뉘어 있습니다. 각 사람은 0부터 n-1까지의 고유 ID로 표시됩니다.

정수 배열 groupSizes가 주어지는데, 여기서 groupSizes[i]는 사람 i가 속한 그룹의 크기입니다. 예를 들어, groupSizes[1] = 3이면, 사람 1은 크기가 3인 그룹에 속해야 합니다.

각 사람 i가 groupSizes[i] 크기의 그룹에 속한 그룹의 목록을 반환하세요.

각 사람은 정확히 하나의 그룹에만 나타나야 하며, 모든 사람은 그룹에 속해야 합니다. 여러 답이 있으면 그 중 아무거나 반환하세요. 주어진 입력에 대해 적어도 하나의 유효한 해결책이 존재함이 보장됩니다.


요약:
이 문제에서는 각 사람이 속해야 할 그룹의 크기를 나타내는 배열을 바탕으로, 모
든 사람이 그들이 속해야 하는 크기의 그룹에 배치되도록 그룹을 구성하는 것이 목표입니다.


풀이 방향:
groupSizes 배열을 순회하면서 각 사람을 적절한 그룹에 배치합니다.
그룹 크기에 따라 사람들을 그룹화하고, 모든 사람이 정확히 하나의 그룹에만 속하도록 합니다.
해시 테이블을 사용하여 각 그룹의 현재 크기를 추적하고, 새로운 그룹이 필요할 때마다 그룹을 추가합니다.
최종적으로 모든 그룹을 포함하는 리스트를 반환합니다.

*/
