class Solution 
{
public:
    int mincostTickets(const vector<int>& travelDays, const vector<int>& ticketCosts) 
    {
        assert(ticketCosts.size() == MAX_TICKET_TYPES);
        assert(1 <= travelDays.size() && travelDays.size() <= MAX_DAYS_IN_YEAR);

        const int totalTravelDays = travelDays.size();
        vector<int> minimumCost(totalTravelDays, numeric_limits<int>::max());

        // 첫 번째 여행 날의 최소 비용 계산
        minimumCost[0] = min({
            ticketCosts[DAILY_TICKET],
            ticketCosts[WEEKLY_TICKET],
            ticketCosts[MONTHLY_TICKET]
        });

        for (int currentDayIndex = 1; currentDayIndex < totalTravelDays; ++currentDayIndex)
        {
            assert(1<= travelDays[currentDayIndex] && travelDays[currentDayIndex] <= MAX_DAYS_IN_YEAR);

            // 1일권
            minimumCost[currentDayIndex] = minimumCost[currentDayIndex - 1] + ticketCosts[DAILY_TICKET];

            { // 7일권
                int lastValidDayIndex = currentDayIndex; 
                while (lastValidDayIndex >= 0 && travelDays[currentDayIndex] - travelDays[lastValidDayIndex] < VALIDITY_PERIOD_WEEKLY)
                {
                    --lastValidDayIndex;
                }
                int costWithWeeklyPass = ticketCosts[WEEKLY_TICKET];
                if (lastValidDayIndex >= 0) 
                {
                    costWithWeeklyPass += minimumCost[lastValidDayIndex];
                }
                minimumCost[currentDayIndex] = min(minimumCost[currentDayIndex], costWithWeeklyPass);
            }

            { // 30일권
                int lastValidDayIndex = currentDayIndex; 
                while (lastValidDayIndex >= 0 && travelDays[currentDayIndex] - travelDays[lastValidDayIndex] < VALIDITY_PERIOD_MONTHLY)
                {
                    --lastValidDayIndex;
                }
                int costWithMonthlyPass = ticketCosts[MONTHLY_TICKET];
                if (lastValidDayIndex >= 0) 
                {
                    costWithMonthlyPass += minimumCost[lastValidDayIndex];
                }
                minimumCost[currentDayIndex] = min(minimumCost[currentDayIndex], costWithMonthlyPass);
            }
        }

        assert(minimumCost.back() != numeric_limits<int>::max());
        return minimumCost.back();
    }

private:
    enum
    {
        DAILY_TICKET = 0,
        WEEKLY_TICKET = 1,
        MONTHLY_TICKET = 2,
        MAX_TICKET_TYPES = 3,
        VALIDITY_PERIOD_WEEKLY = 7,
        VALIDITY_PERIOD_MONTHLY = 30,
        MAX_DAYS_IN_YEAR = 365
    };
};

// https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=daily-question&envId=2024-12-31

/*
**983. 티켓 최소 비용**  
**난이도**: Medium  

---

### 문제 설명

당신은 1년 동안 기차 여행을 계획하고 있습니다. 여행할 날짜는 정수 배열 `days`로 주어지며, 각 날짜는 1부터 365 사이의 정수입니다.  

기차 티켓은 세 가지 형태로 판매됩니다:  
1. **1일권**: `costs[0]` 달러.  
2. **7일권**: `costs[1]` 달러.  
3. **30일권**: `costs[2]` 달러.  

각 티켓은 해당 기간 동안 연속적으로 여행할 수 있도록 허용합니다.  
예를 들어, **2일째에 7일권을 구매하면 2일부터 8일까지 여행할 수 있습니다**.  

목표는 주어진 `days` 배열에서 모든 날짜에 여행할 수 있도록 필요한 최소 비용을 계산하는 것입니다.  

---

### 예제

**예제 1**:  
- **입력**:  
  ```text
  days = [1,4,6,7,8,20], costs = [2,7,15]
  ```
- **출력**:  
  ```text
  11
  ```
- **설명**:  
  다음은 여행 계획을 충족하기 위해 티켓을 구매하는 방법 중 하나입니다:
  1. 1일째에 **1일권**을 구매 (`costs[0] = $2`), 이는 1일을 커버합니다.
  2. 3일째에 **7일권**을 구매 (`costs[1] = $7`), 이는 3일부터 9일까지 커버합니다.
  3. 20일째에 **1일권**을 구매 (`costs[0] = $2`), 이는 20일을 커버합니다.  
  총 비용은 $11입니다.  

---

**예제 2**:  
- **입력**:  
  ```text
  days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
  ```
- **출력**:  
  ```text
  17
  ```
- **설명**:  
  다음은 여행 계획을 충족하기 위해 티켓을 구매하는 방법 중 하나입니다:
  1. 1일째에 **30일권**을 구매 (`costs[2] = $15`), 이는 1일부터 30일까지 커버합니다.
  2. 31일째에 **1일권**을 구매 (`costs[0] = $2`), 이는 31일을 커버합니다.  
  총 비용은 $17입니다.  

---

### 제약 조건
1. \(1 \leq \text{days.length} \leq 365\)
2. \(1 \leq \text{days}[i] \leq 365\)
3. `days`는 **엄격히 증가하는 순서**로 정렬됩니다.
4. \( \text{costs.length} = 3 \)
5. \(1 \leq \text{costs}[i] \leq 1000\)  

---

### 문제 풀이 힌트
- **동적 계획법(DP)**를 사용하여 최소 비용을 계산할 수 있습니다.
- 특정 날짜까지의 최소 비용을 저장하는 배열 `dp`를 정의합니다.
- 각 날짜마다 다음 세 가지 선택지를 고려하여 최소 비용을 계산합니다:
  1. 1일권을 구매.
  2. 7일권을 구매.
  3. 30일권을 구매.
- `days` 배열에 없는 날짜는 이전 날짜의 비용과 동일하게 설정합니다.  
*/
