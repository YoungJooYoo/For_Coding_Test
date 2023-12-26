class RecentCounter {
public:
    RecentCounter() 
    {
    }

    int ping(const int t)
    {
        requests.push(t); // 현재 시간 요청 추가

        // 3000 밀리초보다 오래된 요청들을 큐에서 제거
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        return requests.size(); // 현재 큐의 크기(요청 수) 반환
    }

private:
    queue<int> requests; // 시간을 저장할 큐
};


 /*
 1. **번역**: RecentCounter 클래스는 특정 시간 범위 내에 발생한 최근 요청 수를 계산합니다. RecentCounter 클래스를 구현하세요:
   - `RecentCounter()`: 카운터를 최근 요청이 없는 상태로 초기화합니다.
   - `int ping(int t)`: 시간 `t`에 새 요청을 추가합니다. 여기서 `t`는 밀리초 단위의 시간을 나타냅니다. 그리고 지난 3000밀리초(새 요청 포함) 동안 발생한 요청 수를 반환합니다. 특히, [t - 3000, t] 범위 내에 발생한 요청 수를 반환합니다.

2. **요약**: 이 문제는 특정 시간 범위 내의 요청 수를 계산하는 RecentCounter 클래스를 구현하는 것입니다. `ping` 함수는 주어진 시간에 요청을 추가하고, 지난 3000밀리초 동안의 요청 수를 반환합니다.

3. **풀이 방향**: 큐(Queue) 또는 리스트(List) 자료구조를 사용하여 각 요청의 시간을 저장합니다. `ping` 함수가 호출될 때마다, 3000밀리초보다 오래된 요청들을 제거하고, 새 요청을 추가한 후, 현재 큐나 리스트의 크기(요청 수)를 반환합니다.
 
 */

// https://leetcode.com/problems/number-of-recent-calls/description/
