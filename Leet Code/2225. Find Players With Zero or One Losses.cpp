class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        vector<int> winners; // 한번도 진적없는 winner
        vector<int> losers; //  한번만 진 loser

        vector<int> win_counts(LENGTH, 0);
        vector<int> lose_counts(LENGTH, 0);

        for (const auto& match : matches) {
            const int winner = match[0];
            const int loser = match[1];
            ++win_counts[winner];
            ++lose_counts[loser];
        }

        for (size_t i = 0; i < LENGTH; ++i) {
            if (win_counts[i] >= 1 && lose_counts[i] == 0) winners.push_back(i);
            else if (lose_counts[i] == 1) losers.push_back(i);
        }

        return {winners, losers};
    }

private:
    enum { LENGTH = 100000 + 1};
};

// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-16


/*
번역:
"2225. 한 패배 또는 패배 없는 플레이어 찾기"
여러분은 정수 배열 matches를 받게 됩니다. 여기서 matches[i] = [winneri, loseri]는 플레이어 winneri가 플레이어 loseri를 경기에서 이겼다는 것을 나타냅니다.

크기가 2인 리스트 answer를 반환하세요. 여기서:

answer[0]은 한 번도 지지 않은 모든 플레이어의 리스트입니다.
answer[1]은 정확히 한 번 지는 플레이어들의 리스트입니다.
두 리스트의 값은 오름차순으로 반환되어야 합니다.
유의사항:

적어도 한 번의 경기에 참가한 플레이어들만 고려합니다.
테스트 케이스는 같은 결과를 가진 두 경기가 없도록 생성됩니다.
요약:
이 문제에서는 경기 결과를 나타내는 배열을 통해 한 번도 지지 않은 플레이어와 정확히 한 번 패배한 플레이어를 각각 오름차순으로 정리하여 반환하는 것이 목표입니다.

풀이 방향:

matches 배열을 순회하며 각 플레이어의 승리와 패배 횟수를 계산합니다.
이 데이터를 기반으로 한 번도 지지 않은 플레이어(answer[0])와 정확히 한 번 패배한 플레이어(answer[1])의 목록을 생성합니다.
두 목록을 오름차순으로 정렬하여 반환합니다.
이 때, 해시 테이블을 사용하여 효율적으로 각 플레이어의 승패를 관리하는 것이 좋습니다.


이 문제는 경기 결과를 나타내는 배열을 분석하여, 특정 선수들의 승패 상황을 파악하는 것입니다. 구체적으로, 한 번도 지지 않은 선수들과 딱 한 번만 진 선수들의 목록을 만들어야 합니다. 이렇게 해서:

answer[0]에는 한 번도 패배하지 않은 선수들의 목록이 들어갑니다. 즉, 이들은 모든 경기에서 승리했거나, 경기에 참여하지 않았을 수도 있습니다.

answer[1]에는 딱 한 번만 패배한 선수들의 목록이 들어갑니다. 이 선수들은 대부분의 경기에서 승리했지만, 한 번은 패배한 경우입니다.

문제 해결을 위해서는 경기 결과를 하나씩 살펴보며 각 선수의 승리와 패배 횟수를 기록해야 합니다. 이를 통해 누가 한 번도 지지 않았는지, 누가 딱 한 번만 졌는지 파악할 수 있습니다. 그 후, 이 정보를 바탕으로 두 목록을 만들고 오름차순으로 정렬하여 결과를 반환하면 됩니다.

*/
