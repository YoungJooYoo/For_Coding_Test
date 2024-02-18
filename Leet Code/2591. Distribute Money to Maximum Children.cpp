class Solution {
public:
    int distMoney(const int money, const int children) {
        
        const int remainingMoneyAfterMinimumDistribution = money - children; // 총 금액에서 아이들이 받아야 하는 최소 금액(1 단위씩)을 뺀 값

        if (remainingMoneyAfterMinimumDistribution < 0) {  // 분배 후 남은 금액이 음수라면 모든 아이들에게 최소 금액조차 주지 못하는 상황
            return -1;
        }

        const int maxChildrenForSevenUnits = remainingMoneyAfterMinimumDistribution / 7; // 7단위로 나눌 수 있는 최대 아이의 수
        const int remainingChildren = children - maxChildrenForSevenUnits; // 나머지 아이들의 수 (7단위를 받지 못하는)
        const int remainingMoney = remainingMoneyAfterMinimumDistribution % 7; // 7단위 분배 후 남은 금액

        if ((remainingChildren == 0 && remainingMoney != 0) || remainingChildren < 0) {
            return children - 1;// 모든 아이들이 최소 금액을 받고, 나머지 금액이 남거나, 남은 아이들이 없는 경우
        }
        if (remainingChildren == 1 && remainingMoney == 3) {
            return maxChildrenForSevenUnits - 1; // 정확히 한 아이에게만 추가로 분배할 수 있는 경우 (남은 금액이 3단위일 때)
        }
        
        return maxChildrenForSevenUnits; // 그 외의 경우, 7단위로 나눌 수 있는 최대 아이의 수 반환
    }
};

// https://leetcode.com/problems/distribute-money-to-maximum-children/description/
