class Solution 
{
public:
    int minimumCost(vector<int>& cost) 
    {
        sort(cost.begin(), cost.end(), greater<int>());
        int totalCost = 0;
        
        for (size_t i = 0; i < cost.size(); ++i)
        {
            if ((i + 1) % 3 != 0)
            {
                totalCost += cost[i];
            }
        }

        return totalCost;
    }
};

// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/

/*
2144. Minimum Cost of Buying Candies With Discount
난이도: 쉬움

문제 설명
한 가게에서 캔디를 할인 판매합니다. 두 개의 캔디를 살 때마다, 세 번째 캔디는 무료로 제공합니다.

고객은 구매한 두 캔디 중 가격이 더 낮거나 같은 캔디를 무료로 가져갈 수 있습니다.

예를 들어, 비용이 1, 2, 3, 4인 4개의 캔디가 있는 경우, 고객이 2와 3의 비용으로 캔디를 사면, 1의 비용으로 캔디를 무료로 가져갈 수 있지만 4의 비용으로 캔디는 가져갈 수 없습니다.

0-인덱스 정수 배열 cost가 주어졌을 때, cost[i]는 i번째 캔디의 비용을 나타냅니다. 모든 캔디를 사는 최소 비용을 반환하세요.

예제
예제 1:

입력: cost = [1, 2, 3]
출력: 5
설명: 비용이 2와 3인 캔디를 사고, 비용이 1인 캔디를 무료로 가져갑니다. 모든 캔디를 사는 총 비용은 2 + 3 = 5입니다.
예제 2:

입력: cost = [6, 5, 7, 9, 2, 2]
출력: 23
설명:
비용이 9와 7인 캔디를 사고, 비용이 6인 캔디를 무료로 가져갑니다.
비용이 5와 2인 캔디를 사고, 마지막 남은 비용이 2인 캔디를 무료로 가져갑니다.
모든 캔디를 사는 최소 비용은 9 + 7 + 5 + 2 = 23입니다.
예제 3:

입력: cost = [5, 5]
출력: 10
설명: 캔디가 2개밖에 없으므로 둘 다 사야 합니다. 무료로 가져갈 수 있는 세 번째 캔디는 없습니다. 따라서 총 비용은 5 + 5 = 10입니다.
제약 조건
1 <= cost.length <= 100
1 <= cost[i] <= 100
*/
