class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        priority_queue<int> pq;
        int count = 0;

        for (const auto elem : amount) {
            pq.push(elem);
        }
        
        while (pq.top() != 0) {
            int num1 = pq.top(); pq.pop();
            int num2 = pq.top(); pq.pop();
            --num1;
            --num2;
            pq.push(num1);
            pq.push(num2);
            ++count;
        }

        return count;
    }
};

// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/

/*

2335. 컵을 채우는 최소 시간

냉수, 온수, 뜨거운 물을 공급할 수 있는 물 디스펜서가 있습니다. 
매 초마다 서로 다른 종류의 물로 2개의 컵을 채우거나, 
어떤 종류의 물이든 1개의 컵을 채울 수 있습니다.

길이가 3인 정수 배열로 된 amount가 주어지는데, 여기서 amount[0], amount[1], amount[2]는 각각 채워야 할 냉수, 온수, 
뜨거운 물 컵의 수를 나타냅니다. 모든 컵을 채우는 데 필요한 최소 시간을 반환하세요.

예시 1:

입력: amount = [1,4,2]
출력: 4
설명: 컵을 채우는 한 가지 방법은:
1초: 냉수 컵과 온수 컵을 채웁니다.
2초: 온수 컵과 뜨거운 물 컵을 채웁니다.
3초: 온수 컵과 뜨거운 물 컵을 채웁니다.
4초: 온수 컵을 채웁니다.
4가 최소 필요한 시간임을 증명할 수 있습니다.
예시 2:

입력: amount = [5,4,4]
출력: 7
설명: 컵을 채우는 한 가지 방법은:
1초: 냉수 컵과 뜨거운 물 컵을 채웁니다.
2초: 냉수 컵과 온수 컵을 채웁니다.
3초: 냉수 컵과 온수 컵을 채웁니다.
4초: 온수 컵과 뜨거운 물 컵을 채웁니다.
5초: 냉수 컵과 뜨거운 물 컵을 채웁니다.
6초: 냉수 컵과 온수 컵을 채웁니다.
7초: 뜨거운 물 컵을 채웁니다.
예시 3:

입력: amount = [5,0,0]
출력: 5
설명: 매 초마다 냉수 컵을 채웁니다.
제한사항:

amount.length == 3
0 <= amount[i] <= 100

*/
