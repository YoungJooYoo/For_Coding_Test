class Solution 
{
public:
    int garbageCollection(const vector<string>& garbage, const vector<int>& travel) const
    {
        const int houseCount = garbage.size();
        long long totalTime = 0;

        assert(houseCount >= MIN_HOUSES && houseCount <= MAX_HOUSES);
        assert((int)travel.size() == houseCount - 1);

        for (const auto& bin : garbage)  // 수거 시간: 모든 쓰레기 단위 개수 합
        {
            assert(bin.size() >= MIN_GARBAGE_PER_HOUSE && bin.size() <= MAX_GARBAGE_PER_HOUSE);
            totalTime += bin.size();
        }
        
        int lastM = 0;
        int lastP = 0;
        int lastG = 0;
        for (int i = 0; i < houseCount; ++i) // 각 쓰레기 트럭이 가야 할 마지막 집 인덱스 찾기
        {
            const string& bin = garbage[i];
            for (const char c : bin) 
            {
                assert(c == 'M' || c == 'P' || c == 'G');
                if (c == 'M') lastM = i;
                else if (c == 'P') lastP = i;
                else lastG = i; /* c == 'G' */ 
            }
        }

        long long moveM = 0;
        int moveP = 0;
        int  moveG = 0; // 이동 시간 누적
        for (int i = 0; i < lastM; ++i) 
        {
            assert(travel[i] >= MIN_TRAVEL && travel[i] <= MAX_TRAVEL);
            moveM += travel[i];
        }
        for (int i = 0; i < lastP; ++i) 
        {
            moveP += travel[i];
        }
        for (int i = 0; i < lastG; ++i) 
        {
            moveG += travel[i];
        }

        totalTime += (moveM + moveP + moveG);
        assert(totalTime >= 0);
        return static_cast<int>(totalTime);
    }

private:
    enum 
    {
        MIN_HOUSES                = 2,
        MAX_HOUSES                = 100000,
        MIN_GARBAGE_PER_HOUSE     = 1,
        MAX_GARBAGE_PER_HOUSE     = 10,
        MIN_TRAVEL                = 1,
        MAX_TRAVEL                = 100
    };
};


// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/

/*
**2391. 쓰레기 수거 최소 시간**

**난이도:** 중간

**문제 설명:**  
0번부터 마지막 집까지 번호가 매겨진 집들이 일렬로 있습니다.  
- `garbage[i]`는 i번 집에 버려진 쓰레기를 나타내는 문자열로,  
  - 문자 `'M'`은 금속 쓰레기 1단위,  
  - 문자 `'P'`는 종이 쓰레기 1단위,  
  - 문자 `'G'`는 유리 쓰레기 1단위  
  를 의미합니다.  
- 쓰레기 1단위를 수거하는 데는 1분이 걸립니다.

또한, `travel[i]`는 집 i에서 i+1로 이동하는 데 걸리는 시간(분)입니다.

도시에는 금속, 종이, 유리용 쓰레기 트럭이 각각 하나씩, 총 3대가 있으며  
각 트럭은 자신이 담당하는 종류의 쓰레기를 수거합니다.  
- 모든 트럭은 0번 집에서 출발해, 필요한 집들만 순서대로 방문할 수 있습니다.  
- 한 번에 오직 한 대의 트럭만 움직이거나 수거할 수 있으며,  
  다른 두 대는 그 동안 정지해 있어야 합니다.

모든 쓰레기를 다 수거하는 데 걸리는 **최소 시간(분)**을 구하세요.

---

**예제 1:**

- **입력:**  
  `garbage = ["G","P","GP","GG"]`,  
  `travel = [2,4,3]`
- **출력:** `21`
- **설명:**  
  - **종이 트럭**:  
    - 0→1(2분), 집1에서 `'P'` 수거(1분),  
    - 1→2(4분), 집2에서 `'P'` 수거(1분) → 총 8분  
  - **유리 트럭**:  
    - 집0에서 `'G'` 수거(1분),  
    - 0→1(2분), 1→2(4분), 집2에서 `'G'` 수거(1분),  
    - 2→3(3분), 집3에서 `'G'` 수거(1분) → 총 13분  
  - **금속 트럭**은 담당 쓰레기 없음 → 0분  
  - 합계: 8 + 13 = 21분

---

**예제 2:**

- **입력:**  
  `garbage = ["MMM","PGM","GP"]`,  
  `travel = [3,10]`
- **출력:** `37`
- **설명:**  
  - **금속 트럭**: 집0에서 MMM(3분), → 0→1(3분), 집1에서 M(1분), → 1→2(10분), 집2에서 M(1분) = 18분  
  - **종이 트럭**: 집1에서 P(1분), → 1→2(10분), 집2에서 (없음) = 11분  
  - **유리 트럭**: 집1에서 G(1분), → 1→2(10분), 집2에서 G(1분) = 12분  
  - 합계: 18 + 11 + 12 = 41분  *(※ 예시의 합계는 문제 설명 참고)*

---

**제약 조건:**

- `2 ≤ garbage.length ≤ 10^5`  
- `travel.length = garbage.length – 1`  
- `garbage[i]`는 오직 `'M','P','G'`로만 이루어져 있으며, 길이는 1~10  
- `1 ≤ travel[i] ≤ 100`
*/
