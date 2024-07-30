class Solution 
{
public:
    int findPoisonedDuration(const vector<int>& timeSeries, int duration) 
    {
        if (timeSeries.empty()) 
        {
            return 0;
        }

        int result = 0;
        for (size_t i = 0; i < timeSeries.size() - 1; ++i)
        {
            const int diff = timeSeries[i + 1] - timeSeries[i]; // 현재 공격과 다음 공격의 시간 차이를 구함
            result += min(diff, duration);  // 실제 중독 시간은 현재 공격의 독 지속 시간과 다음 공격까지의 시간 차이 중 작은 값
        }
        
        result += duration;  // 마지막 공격은 항상 duration 동안 중독됨
        
        return result;
    }
};

// https://leetcode.com/problems/teemo-attacking/

/*


우리의 주인공 티모는 독 공격으로 적 애쉬를 공격하고 있습니다! 티모가 애쉬를 공격하면 애쉬는 정확히 duration 초 동안 독에 중독됩니다. 더 구체적으로, t 초에 공격이 발생하면 애쉬는 포함된 시간 간격 [t, t + duration - 1] 동안 중독됩니다. 티모가 독 효과가 끝나기 전에 다시 공격하면 타이머가 리셋되어 독 효과는 새로운 공격 후 duration 초 후에 끝납니다.

당신에게 비내림차순의 정수 배열 timeSeries가 주어집니다. 이 배열의 각 요소는 티모가 애쉬를 공격한 시간 timeSeries[i]를 나타냅니다. 또한, 정수 duration도 주어집니다.

애쉬가 독에 중독된 총 시간을 반환하세요.

예시 1:
입력: timeSeries = [1, 4], duration = 2
출력: 4
설명: 티모가 애쉬를 다음과 같이 공격합니다:
1초에 티모가 공격하고, 애쉬는 1초와 2초 동안 중독됩니다.
4초에 티모가 다시 공격하고, 애쉬는 4초와 5초 동안 중독됩니다.
따라서 애쉬는 총 4초 동안 중독됩니다.
예시 2:
입력: timeSeries = [1, 2], duration = 2
출력: 3
설명: 티모가 애쉬를 다음과 같이 공격합니다:
1초에 애쉬는 1초와 2초 동안 중독됩니다.
그러나 2초에 티모가 다시 공격하고 독 타이머를 리셋합니다. 애쉬는 2초와 3초 동안 중독됩니다.
따라서 애쉬는 총 3초 동안 중독됩니다.
제약 사항:
1 <= timeSeries.length <= 10^4
0 <= timeSeries[i], duration <= 10^7
timeSeries는 비내림차순으로 정렬되어 있습니다.

*/
