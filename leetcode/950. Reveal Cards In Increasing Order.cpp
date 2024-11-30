class Solution 
{
public:
    vector<int> deckRevealedIncreasing(const vector<int>& deck) 
    {
        const size_t deckSize = deck.size();
        vector<int> sortedDeck = deck;
        vector<int> result(deckSize);
        queue<int> indexQueue;

        sort(sortedDeck.begin(), sortedDeck.end()); // 오름차순 정렬

        for (size_t i = 0; i < deckSize; ++i)
        {
            indexQueue.push(i);
        }

        for (const int card : sortedDeck)
        {
            result[indexQueue.front()] = card;
            indexQueue.pop();
            if (!indexQueue.empty())
            {
                indexQueue.push(indexQueue.front());
                indexQueue.pop();
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/

/*

950. 증가하는 순서로 카드 공개하기
난이도: 중간

정수 배열 deck이 주어집니다. 카드 더미에는 각 카드에 고유한 정수가 있습니다. i번째 카드에는 deck[i]라는 정수가 적혀 있습니다.

카드를 임의의 순서로 정렬할 수 있으며, 처음에는 모든 카드를 뒤집어서 한 더미로 만듭니다.

모든 카드가 공개될 때까지 다음 단계를 반복해서 수행합니다:

	1.	카드 더미에서 맨 위 카드를 꺼내어 공개하고, 해당 카드를 더미에서 제거합니다.
	2.	아직 카드가 더미에 남아 있으면, 다음 맨 위 카드를 카드 더미의 맨 아래로 옮깁니다.
	3.	아직 공개되지 않은 카드가 있다면 1단계로 돌아갑니다. 그렇지 않으면 종료합니다.

카드가 오름차순으로 공개되도록 더미를 정렬한 결과를 반환하세요.

첫 번째 항목은 답에서 더미의 맨 위에 있는 카드로 간주합니다.

예제 1:

입력:

deck = [17,13,11,2,3,5,7]

출력:

[2,13,3,11,5,17,7]

설명:

	•	처음 카드 더미는 [17,13,11,2,3,5,7] (이 순서는 상관없음)이며, 이를 재정렬합니다.
	•	재정렬 후 카드 더미는 [2,13,3,11,5,17,7]로 시작하며, 2가 맨 위에 있습니다.
	•	2를 공개하고, 13을 맨 아래로 옮깁니다. 더미는 이제 [3,11,5,17,7,13]입니다.
	•	3을 공개하고, 11을 맨 아래로 옮깁니다. 더미는 이제 [5,17,7,13,11]입니다.
	•	5를 공개하고, 17을 맨 아래로 옮깁니다. 더미는 이제 [7,13,11,17]입니다.
	•	7을 공개하고, 13을 맨 아래로 옮깁니다. 더미는 이제 [11,17,13]입니다.
	•	11을 공개하고, 17을 맨 아래로 옮깁니다. 더미는 이제 [13,17]입니다.
	•	13을 공개하고, 17을 맨 아래로 옮깁니다. 더미는 이제 [17]입니다.
	•	17을 공개합니다.
	•	모든 카드가 오름차순으로 공개되었으므로 답은 맞습니다.

예제 2:

입력:

deck = [1,1000]

출력:

[1,1000]

제약 조건:

	•	1 <= deck.length <= 1000
	•	1 <= deck[i] <= 10^6
	•	모든 deck 값은 고유합니다.


*/
