class Solution 
{
public:
    string bestHand(const vector<int>& ranks, const vector<char>& suits) 
    {
        const unordered_set<char> suitSet(suits.begin(), suits.end());

        if (suitSet.size() == 1)
        {
            return "Flush";
        }

        unordered_map<int, int> rankCount;
        for (const int rank : ranks) 
        {
            ++rankCount[rank];
        }

        bool isPair = false;

        for (const auto& [rank, count] : rankCount)
        {
            if (count >= 3)
            {
                return "Three of a Kind";
            }
            else if (count == 2)
            {
                isPair = true;
            }
        }

        return (isPair == true) ? "Pair" : "High Card";
    }
};


// https://leetcode.com/problems/best-poker-hand/description/

/*


2347. 최고의 포커 핸드
난이도: 쉬움

문제 설명
정수 배열 ranks와 문자 배열 suits가 주어집니다. 당신에게는 5장의 카드가 있으며, i번째 카드는 ranks[i]의 랭크와 suits[i]의 슈트를 가집니다.

다음은 가장 좋은 포커 핸드 순서대로 나열한 것입니다:

"Flush": 동일한 슈트의 5장 카드.
"Three of a Kind": 동일한 랭크의 3장 카드.
"Pair": 동일한 랭크의 2장 카드.
"High Card": 위의 어떤 핸드도 만족하지 않는 경우.
주어진 카드로 만들 수 있는 최고의 포커 핸드를 나타내는 문자열을 반환하세요.

반환값은 대소문자를 구분합니다.

예제
예제 1:

입력: ranks = [13, 2, 3, 1, 9], suits = ["a", "a", "a", "a", "a"]
출력: "Flush"
설명: 모든 카드가 동일한 슈트를 가지므로 "Flush"입니다.
예제 2:

입력: ranks = [4, 4, 2, 4, 4], suits = ["d", "a", "a", "b", "c"]
출력: "Three of a Kind"
설명: 첫 번째, 두 번째, 네 번째 카드가 동일한 랭크를 가지므로 "Three of a Kind"입니다. "Pair"도 만들 수 있지만, "Three of a Kind"가 더 좋은 핸드입니다.
예제 3:

입력: ranks = [10, 10, 2, 12, 9], suits = ["a", "b", "c", "a", "d"]
출력: "Pair"
설명: 첫 번째와 두 번째 카드가 동일한 랭크를 가지므로 "Pair"입니다. "Flush"나 "Three of a Kind"는 만들 수 없습니다.
제약 조건
ranks.length == suits.length == 5
1 <= ranks[i] <= 13
'a' <= suits[i] <= 'd'
같은 랭크와 슈트를 가진 두 카드는 없습니다.

*/
